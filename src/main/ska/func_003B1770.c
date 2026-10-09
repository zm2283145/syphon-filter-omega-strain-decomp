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

float func_003B17A0(char* self) {
    return *(float*)(self + 8);
}

/* Address of element i in an array of 60-byte elements. */
char* func_003B17B0(SkaVec* v, int i) {
    return v->data + i * 60;
}
