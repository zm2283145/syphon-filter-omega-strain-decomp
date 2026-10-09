/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GenInfoObject.cc (ends 0x0043BA00),
 * before guiMLTextWidget.cc (starts 0x0043DB80).
 */

#include "types.h"

Word* func_0043DB50(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0043DB60(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0043DB70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
