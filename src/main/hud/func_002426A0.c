/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7DB8[];
extern void func_00261350(int);

Word* func_002426A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002426B0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002426C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002426D0(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    *(int*)D_004F7DB8 = tmp0;
    func_00261350(a0);
}
