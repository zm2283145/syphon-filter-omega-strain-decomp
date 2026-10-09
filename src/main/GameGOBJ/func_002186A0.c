/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

void func_002186A0(IntFloatVec* v) {
    v->count = v->count - 1;
}

IntFloat* func_002186B0(IntFloat* dst, IntFloat* src) {
    dst->i = src->i;
    dst->f = src->f;
    return dst;
}

IntFloat* func_002186D0(IntFloatVec* v, int i) {
    return &v->data[i];
}

int func_002186E0(IntFloatVec* v) {
    return v->count;
}
