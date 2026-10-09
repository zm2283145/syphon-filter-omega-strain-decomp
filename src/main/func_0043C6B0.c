/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GenInfoObject.cc (ends 0x0043BA00),
 * before guiMLTextWidget.cc (starts 0x0043DB80).
 */

#include "types.h"

Quad* func_0043C6B0(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
