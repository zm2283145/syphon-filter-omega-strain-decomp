/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void** PtrStack_Top(PtrStack* s) {
    return &s->items[s->count - 1];
}

int AnimContext_GetCount(char* self) {
    return *(int*)(self + 0);
}

float cSkaSliderValue_opCast_float(char* self) {
    return *(float*)(self + 8);
}

/* Address of element i in an array of 60-byte elements. */
char* cArray_cSkaSliderValue_opIndex(SkaVec* v, int i) {
    return v->data + i * 60;
}
