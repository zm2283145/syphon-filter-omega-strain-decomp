/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0014D390(int a0, int a1) {
    int v0, v1;

    v1 = a1 & 255;
    v0 = v1 << 2;
    v0 = v0 + v1;
    v0 = v0 << 2;
    v0 = v0 + a0;
    v0 = *(unsigned char*)(char*)(v0 + 380);
    goto ret;
ret:
    return v0;
}

signed char func_0014D3B0(signed char* self) {
    return self[316];
}

float func_0014D3C0(char* self) {
    return *(float*)(self + 96);
}
