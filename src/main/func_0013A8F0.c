/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

unsigned char func_0013A8F0(unsigned char* self) {
    return self[32];
}

ElemE0* func_0013A900(ElemE0Iter* it) {
    return it->p;
}

/* End iterator of an array of 0xE0-byte records. */
void func_0013A910(ElemE0Iter* out, VecE0Array* v) {
    out->p = v->data + v->count;
}

void func_0013A930(Iter* out, PtrVec* v) {
    out->p = v->data;
}
