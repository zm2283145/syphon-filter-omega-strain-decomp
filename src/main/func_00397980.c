/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Quad* _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Point a cursor at a word buffer. */
void _cdeque_deleter_common_int_begin(WordCursor* out, WordBuf* buf) {
    out->end = buf->data + buf->count;
    out->begin = buf->data;
    out->cur = out->begin + buf->count;
    out->limit = out->begin + buf->capacity;
}

void MotionGroup_ClearContributions(char* self) {
    *(int*)(self + 4) = 0;
}
