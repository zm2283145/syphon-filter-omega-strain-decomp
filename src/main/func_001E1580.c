/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

FlagElem16* func_001E1580(FlagElem16Iter* it) {
    return it->p;
}

Elem60* func_001E1590(Elem60Iter* it) {
    return it->p;
}

/* End iterator of an array of 16-byte elements. */
void func_001E15A0(FlagElem16Iter* out, Vec16Array* v) {
    out->p = v->data + v->count;
}

void func_001E15C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x60-byte records. */
void func_001E15D0(Elem60Iter* out, Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

void func_001E15F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
