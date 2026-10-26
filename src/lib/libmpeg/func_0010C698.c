/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceIpuStopDMA(int);
extern int sceIpuRestartDMA(int);

int _defStopDMA(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    sceIpuStopDMA((tmp0 + 104));
    return 1;
}

int _defRestartDMA(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 64);
    sceIpuRestartDMA((tmp0 + 104));
    return 1;
}
