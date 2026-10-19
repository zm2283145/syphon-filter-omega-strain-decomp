/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

static const unsigned int dat_00485EA0[4] = { 0x20001, 0x30001, 0x0, 0x0 };

int sceGsGetGParam(void) {
    return (int)((char*)dat_00485EA0);
}
