/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int func_003B7470(SkaVec* v, char* pos, int n, int value);

Rel* func_003B1560(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

unsigned char func_003B1580(unsigned char* self) {
    return self[69];
}

/* Append one 32-byte element at the end of the array. */
int func_003B1590(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return func_003B7470(v, data + (count << 5), 1, value);
}
