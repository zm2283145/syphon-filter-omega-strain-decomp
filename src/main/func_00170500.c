/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE6E0[];
extern char D_004FFBD0[];
extern int PtrVec_Insert(int, int, int, int);
extern int func_00170500(int, int);
extern int func_00170E20(int, int, int, int);

int func_00170500(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

int func_00170520(int a0) {
    int loc[1];
    int a1, a2, a3, v0;

    a1 = a0;
    a0 = *(int*)(char*)D_004FFBD0;
    a2 = 0;
    a3 = 0;
    v0 = func_00170E20(a0, a1, a2, a3);
    *(int*)(char*)loc = v0;
    a0 = (int)D_004EE6E0;
    a1 = (int)loc;
    v0 = func_00170500(a0, a1);
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
