/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00380C90(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_00380CB0(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_00380CC0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a1;
    tmp1 = *(int*)((char*)tmp0 + 4);
    *(int*)((char*)a1) = tmp1;
    *(int*)((char*)a0) = tmp0;
}
