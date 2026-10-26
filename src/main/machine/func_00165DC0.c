/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A700[];
extern int cUSBKeybd_Init(void* obj);

int cMachine_InitUSB(void) {
    return cUSBKeybd_Init(D_0055A700);
}
