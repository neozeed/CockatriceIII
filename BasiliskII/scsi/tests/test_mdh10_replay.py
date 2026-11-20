#!/usr/bin/env python3
"""Replay Bus Hound captures of a real Sony MDH-10 against the emulation.

Usage:
    python3 -I test_mdh10_replay.py ./test_mdh10 image.img capture.txt [capture2.txt ...]

Every CDB (with its data-out phase) from the capture is sent to the emulated
drive through "test_mdh10 --replay".  Commands that Bus Hound collapsed with a
"(n)" repeat count are sent once.  For each command the status, the sense
key/ASC/ASCQ and the data-in bytes (Bus Hound keeps at most 4096) are compared
with the real drive.  READ data is reported separately because it depends on
the disc contents, not on the drive.  The image is modified: use a scratch copy.
"""
import re
import subprocess
import sys
from collections import Counter

ROW = re.compile(r'^\s*\d+\s+(CMD|IN|OUT|SENSE|ok)\s+(.*)$')
HEXRUN = re.compile(r'^((?:[0-9a-f]{2}\s{1,2})*[0-9a-f]{2})')
CONT = re.compile(r'^\s{10,}((?:[0-9a-f]{2}\s{1,2})*[0-9a-f]{2})')

READS = {0x08, 0x28}


def parse(path):
    """Yield transactions: dict(cdb, out, din, sense, ok)."""
    cur = None
    phase = None
    with open(path, encoding='latin-1') as f:
        for line in f:
            line = line.rstrip('\r\n')
            m = ROW.match(line)
            if m:
                phase, rest = m.group(1), m.group(2)
                h = HEXRUN.match(rest)
                data = bytes.fromhex(h.group(1)) if h else b''
                if phase == 'CMD':
                    if cur:
                        yield cur
                    cur = {'cdb': data, 'out': b'', 'din': b'', 'sense': None, 'ok': False}
                elif cur is None:
                    continue
                elif phase == 'OUT':
                    cur['out'] += data
                elif phase == 'IN':
                    cur['din'] += data
                elif phase == 'SENSE':
                    cur['sense'] = data
                elif phase == 'ok':
                    cur['ok'] = True
                continue
            m = CONT.match(line)
            if m and cur is not None and phase in ('CMD', 'OUT', 'IN', 'SENSE'):
                data = bytes.fromhex(m.group(1))
                key = {'CMD': 'cdb', 'OUT': 'out', 'IN': 'din', 'SENSE': 'sense'}[phase]
                cur[key] = (cur[key] or b'') + data
    if cur:
        yield cur


def main():
    if len(sys.argv) < 4:
        print(__doc__)
        return 2
    tool, image, captures = sys.argv[1], sys.argv[2], sys.argv[3:]
    proc = subprocess.Popen([tool, '--replay', image], stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, text=True)
    total_fail = 0
    for cap in captures:
        stats = Counter()
        fails = []
        for n, t in enumerate(parse(cap)):
            cdb = t['cdb']
            if len(cdb) not in (6, 10, 12):
                continue
            proc.stdin.write(cdb.hex() + '|' + t['out'].hex() + '\n')
            proc.stdin.flush()
            reply = proc.stdout.readline()
            while reply and reply.count('|') != 2:     # skip informational messages
                reply = proc.stdout.readline()
            st, din, sense = reply.rstrip('\n').split('|')
            st = int(st, 16)
            din = bytes.fromhex(din)
            sense = bytes.fromhex(sense)
            op = cdb[0]
            stats['commands'] += 1
            real_check = t['sense'] is not None
            problems = []
            if real_check != (st == 2):
                problems.append('status real=%s emu=%02x' % ('CHECK' if real_check else 'GOOD', st))
            elif real_check:
                rs = t['sense']
                if len(rs) >= 14 and len(sense) >= 14 and (rs[2] & 0x0f, rs[12], rs[13]) != (sense[2], sense[12], sense[13]):
                    problems.append('sense real=%02x/%02x/%02x emu=%02x/%02x/%02x' %
                                    (rs[2] & 0x0f, rs[12], rs[13], sense[2], sense[12], sense[13]))
            if t['din'] and st == 0:
                cmp = din[:len(t['din'])]
                if op in READS:
                    stats['reads'] += 1
                    if cmp == t['din']:
                        stats['reads_identical'] += 1
                elif cmp != t['din']:
                    problems.append('data-in differs (real %s.. emu %s..)' % (t['din'][:16].hex(), din[:16].hex()))
            if problems:
                fails.append((n, cdb.hex(' '), '; '.join(problems)))
            else:
                stats['match'] += 1
        print('== %s: %d commands, %d match (status/sense/data), READ data identical %d/%d' %
              (cap, stats['commands'], stats['match'], stats['reads_identical'], stats['reads']))
        for n, c, p in fails[:40]:
            print('   #%d  %s  -> %s' % (n, c, p))
        if len(fails) > 40:
            print('   ... %d more' % (len(fails) - 40))
        total_fail += len(fails)
    proc.stdin.close()
    proc.wait()
    return 1 if total_fail else 0


if __name__ == '__main__':
    sys.exit(main())
