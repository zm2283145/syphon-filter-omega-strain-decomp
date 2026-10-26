/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int AdjustTime(int, int);

int sceScfGetGMTfromRTC(int a0) {
    return AdjustTime(a0, -540);
}
