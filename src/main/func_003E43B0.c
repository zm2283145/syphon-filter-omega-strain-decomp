/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0840[];
extern char D_0055D480[];
extern int cMessage_ctor5(int, int, int);

Vec4* func_003E43B0(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

int func_003E43D0(int a0, int a1) {
    unsigned char tmp2;
    unsigned char tmp3;

    cMessage_ctor5(a0, (int)D_0055D480, a1);
    *(int*)((char*)a0) = (int)D_004E0840;
    tmp2 = *(unsigned char*)((char*)a1 + 8);
    *(int*)((char*)a0 + 36) = tmp2;
    tmp3 = *(unsigned char*)((char*)a1 + 9);
    *(char*)((char*)a0 + 40) = tmp3;
    return a0;
}
