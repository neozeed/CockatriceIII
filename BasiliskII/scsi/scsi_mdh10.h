/*
 *  scsi_mdh10.h - Sony MDH-10 / MDM-110 MD-DATA drive emulation
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  The device model is self contained (stdio only) so it can be unit tested
 *  outside the emulator. See scsi_mdh10.cpp for the behaviour description.
 */

#ifndef SCSI_MDH10_H
#define SCSI_MDH10_H

#include <stdint.h>

struct MDH10Device;

// Open an MD-DATA image (raw 2048-byte sectors, LBA 0 at offset 0).
// If the file does not exist a blank (unformatted) 70464-sector disc is created.
// model: "MDH-10" (default when NULL/empty) or "MDM110"/"MDM-110".
// Returns NULL on failure.
MDH10Device *mdh10_open(const char *image_path, const char *model);
void mdh10_close(MDH10Device *dev);

// Execute one SCSI command.
//   data_out/out_len : data sent by the initiator (write-type commands)
//   *data_in/*in_len : data returned to the initiator; points to a buffer owned
//                      by the device, valid until the next call
// Returns the SCSI status byte (0x00 GOOD, 0x02 CHECK CONDITION).
uint8_t mdh10_command(MDH10Device *dev, const uint8_t *cdb, int cdb_len,
                      const uint8_t *data_out, uint32_t out_len,
                      const uint8_t **data_in, uint32_t *in_len);

// Medium handling
bool mdh10_eject(MDH10Device *dev);
bool mdh10_insert(MDH10Device *dev);
bool mdh10_medium_present(MDH10Device *dev);

// Thread-safe request (e.g. from the UI hotkey) to re-insert the configured
// image into every MDH-10 drive whose tray is empty. Processed on the next
// SCSI command addressed to the drive.
void mdh10_request_insert(void);

// Test hook: replace the millisecond clock used for FORMAT UNIT progress.
void mdh10_set_clock(uint64_t (*now_ms)(void));

#endif
