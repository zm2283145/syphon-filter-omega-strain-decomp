/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Quad* func_00397980(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Point a cursor at a word buffer. */
void func_003979B0(WordCursor* out, WordBuf* buf) {
    out->end = buf->data + buf->count;
    out->begin = buf->data;
    out->cur = out->begin + buf->count;
    out->limit = out->begin + buf->capacity;
}

void func_00397A00(char* self) {
    *(int*)(self + 4) = 0;
}
