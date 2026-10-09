/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Word* func_00396AF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00396B00(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00396B10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/*
 * Builds a four-word cursor: [0] = a2, [1] = base (src[3]),
 * [2] = base + src[2] words, [3] = base + src[0] words.
 */
int** func_00396B20(int** dst, int* src, int* a2) {
    dst[0] = a2;
    dst[1] = (int*)src[3];
    dst[2] = dst[1] + src[2];
    dst[3] = dst[1] + src[0];
    return dst;
}

void* func_00396B60(void* self) {
    return self;
}

void func_00396B70(char* self) {
    *(int*)(self + 4) = 0;
}
