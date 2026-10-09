/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

float func_003ADEB0(char* self) {
    return *(float*)(self + 4);
}

int func_003ADEC0(char* self) {
    return *(int*)(self + 0);
}

/* End iterator of an array of 32-byte elements. */
void func_003ADED0(Iter16* out, SkaVec* v) {
    out->p = v->data + (v->count << 5);
}

void func_003ADEF0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
