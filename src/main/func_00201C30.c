/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFBF0[];
extern int func_001325F0(int, int);
extern int func_00201CE0(int, int);
extern int func_00201D20(int);
extern int func_00201D50(int, int);
extern int func_00201EA0(int, int);

int func_00201C30(int a0, int a1) {
    signed char tmp0;

    tmp0 = *(signed char*)((char*)a1 + 4);
    *(char*)((char*)a0 + 4) = tmp0;
    func_001325F0((a0 + 16), (a1 + 16));
    return a0;
}

int func_00201C70(int a0, int a1) {
    int tmp2;
    unsigned char tmp5;
    unsigned char tmp6;

    func_00201EA0(a0, a1);
    *(int*)((char*)a0) = (int)D_004DFBF0;
    tmp2 = *(int*)((char*)a1 + 32);
    *(int*)((char*)a0 + 32) = tmp2;
    func_00201CE0((a0 + 36), (a1 + 36));
    tmp5 = *(unsigned char*)((char*)a1 + 52);
    *(char*)((char*)a0 + 52) = tmp5;
    tmp6 = *(unsigned char*)((char*)a1 + 53);
    *(char*)((char*)a0 + 53) = tmp6;
    return a0;
}

int func_00201CE0(int a0, int a1) {
    int s0, s1, v0, v1;

    s1 = a0;
    s0 = a1;
    v0 = func_00201D20(a0);
    v1 = *(unsigned char*)(char*)(s0 + 12);
    v0 = s1;
    *(char*)(char*)(s1 + 12) = v1;
    goto ret;
ret:
    return v0;
}

int func_00201D20(int a0, int a1) {
    func_00201D50(a0, a1);
    return a0;
}
