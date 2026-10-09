/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Quad* func_001EAF30(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

int HumanColPreset_SetConfig(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    int v0, v1;
    float f0;

    *(char*)(char*)a0 = a1;
    v1 = 0xff7f0000;
    a2 = *(int*)(char*)a2;
    a1 = 0 + -1;
    v1 = v1 | 0xffff;
    v0 = a0;
    *(int*)(char*)(a0 + 4) = a2;
    a2 = *(int*)(char*)a3;
    *(int*)(char*)(a0 + 8) = a2;
    a2 = *(int*)(char*)t0;
    *(int*)(char*)(a0 + 12) = a2;
    a2 = *(int*)(char*)t1;
    *(int*)(char*)(a0 + 16) = a2;
    f0 = *(float*)(char*)t2;
    *(float*)(char*)(a0 + 20) = f0;
    f0 = *(float*)(char*)(t2 + 4);
    *(float*)(char*)(a0 + 24) = f0;
    f0 = *(float*)(char*)(t2 + 8);
    *(float*)(char*)(a0 + 28) = f0;
    f0 = *(float*)(char*)(t2 + 12);
    *(float*)(char*)(a0 + 32) = f0;
    f0 = *(float*)(char*)(t2 + 16);
    *(float*)(char*)(a0 + 36) = f0;
    f0 = *(float*)(char*)(t2 + 20);
    *(float*)(char*)(a0 + 40) = f0;
    a2 = *(unsigned char*)(char*)(t2 + 24);
    *(char*)(char*)(a0 + 44) = a2;
    *(char*)(char*)(a0 + 48) = t3;
    *(char*)(char*)(a0 + 49) = 0;
    *(char*)(char*)(a0 + 50) = 0;
    *(char*)(char*)(a0 + 112) = 0;
    *(int*)(char*)(a0 + 144) = a1;
    *(int*)(char*)(a0 + 148) = a1;
    *(int*)(char*)(a0 + 152) = 0;
    *(int*)(char*)(a0 + 160) = 0;
    *(int*)(char*)(a0 + 224) = v1;
    *(int*)(char*)(a0 + 228) = 0;
    goto ret;
ret:
    return v0;
}
