/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D8[];
extern int PtrVec_Insert(int, int, int, int);
extern int func_00282530(int, int);
extern int func_00282550(void);

int func_002824D0(int a0, int a1) {
    int loc[1];
    int s0, v0;

    *(int*)(char*)loc = a0;
    s0 = a1;
    v0 = func_00282550();
    a0 = v0;
    a1 = (int)loc;
    v0 = func_00282530(a0, a1);
    v0 = *(int*)(char*)D_005061D8;
    *(int*)(char*)s0 = v0;
    v0 = *(int*)(char*)D_005061D8;
    v0 = v0 + 1;
    *(int*)(char*)D_005061D8 = v0;
    v0 = *(int*)(char*)s0;
    goto ret;
ret:
    return v0;
}

int func_00282530(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
