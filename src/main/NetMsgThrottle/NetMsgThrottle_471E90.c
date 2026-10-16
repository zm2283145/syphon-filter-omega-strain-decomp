/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after inventory.cc (ends 0x004719B0),
 * before NetMsgThrottle.cc (starts 0x00472050).
 */

#include "types.h"

Word* func_00471E90(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00471EA0(Iter* out, Tree* t) {
    out->p = &t->header;
}
