/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0013D890(int, int);
extern int func_001F2F20(int, int);

Word* func_001F2ED0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001F2EE0(int a0) {
    int loc[1];
    int a1, s0, v0;

    s0 = a0;
    a0 = (int)loc;
    func_0013D890(a0, a1);
    a1 = *(int*)(char*)loc;
    a0 = s0;
    v0 = func_001F2F20(a0, a1);
    goto ret;
ret:;
}
