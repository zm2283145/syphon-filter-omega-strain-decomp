/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

Rel* AnimRoot_InitRelations(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

SkaDirtyFlags* AnimRoot_CopyDirtyFlags(SkaDirtyFlags* dst, SkaDirtyFlags* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    return dst;
}
