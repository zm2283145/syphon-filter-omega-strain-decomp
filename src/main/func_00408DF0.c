/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0013BCB0(L4Elem124Vec*, int);

void func_00408DF0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem124* func_00408E00(L4Elem124Vec* v) {
    return v->data + v->count;
}

int func_00408E30(L4Elem124Vec* v, int a1, int value) {
    int ret = func_0013BCB0(v, a1);

    v->unk0C = value;
    return ret;
}

Word* func_00408E70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00408E80(Iter* out, Tree* t) {
    out->p = &t->header;
}

void* func_00408E90(char* self) {
    return self + 8;
}
