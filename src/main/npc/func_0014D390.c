/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cNPC_v28(int a0, int a1) {
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

signed char cNPC_v27(signed char* self) {
    return self[316];
}

float cNPC_v34(char* self) {
    return *(float*)(self + 96);
}
