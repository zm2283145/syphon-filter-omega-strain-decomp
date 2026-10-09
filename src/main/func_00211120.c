/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54F0[];
extern char D_004F5540[];
extern char D_004F5548[];
extern char D_004F5610[];
extern char D_00555070[];
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

int func_00211120(void) {
    int tmp0;
    int tmp1;
    int tmp4;
    int tmp5;
    int tmp6;

    tmp0 = *(int*)D_004F5548;
    tmp1 = *(int*)D_004F54F0;
    func_003D9440(tmp0, tmp1);
    tmp4 = *(int*)D_004F5548;
    tmp5 = *(int*)D_004F5610;
    tmp6 = func_003D9400(tmp4, tmp5);
    return tmp6;
}

int func_00211160(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5540;
    return tmp0;
}

int func_00211170(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

int func_00211190(Args* a) {
    union { int i; float f; } u;
    u.i = a->arg1;
    a->obj->speed = u.f;
    return 0;
}
