/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

float cSkaPlaybackItem_GetSummedWeight(char* self) {
    return *(float*)(self + 4);
}

int cArray_cSkaPlaybackItem_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* End iterator of an array of 32-byte elements. */
void cArray_cSkaPlaybackItem_End(Iter16* out, SkaVec* v) {
    out->p = v->data + (v->count << 5);
}

void cArray_cSkaPlaybackItem_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
