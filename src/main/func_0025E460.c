/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC30[];

int Script_setFxLightDist(int a0) {
    int loc[1];
    int at, v0, v1;
    float f0;
    int cond;

    v0 = *(int*)(char*)(a0 + 4);
    v1 = *(int*)(char*)D_004FFC30;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    at = (unsigned int)v0 < (unsigned int)5;
    cond = at == 0;
    f0 = *(float*)(char*)loc;
    if (cond) goto L0025E490;
    v0 = v0 << 6;
    v0 = v0 + v1;
    *(float*)(char*)(v0 + 116) = f0;
L0025E490:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
