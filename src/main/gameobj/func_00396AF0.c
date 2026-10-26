/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Word* cLListIterator_cSkaPlaybackGroupPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkaPlaybackGroupPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/*
 * Builds a four-word cursor: [0] = a2, [1] = base (src[3]),
 * [2] = base + src[2] words, [3] = base + src[0] words.
 */
int** _cdeque_deleter_common_int_generic_iterator_ctor(int** dst, int* src, int* a2) {
    dst[0] = a2;
    dst[1] = (int*)src[3];
    dst[2] = dst[1] + src[2];
    dst[3] = dst[1] + src[0];
    return dst;
}

void* _cdeque_deleter_common_int_cap(void* self) {
    return self;
}

void std_vector_deleter_cBoneScale_clear(char* self) {
    *(int*)(self + 4) = 0;
}
