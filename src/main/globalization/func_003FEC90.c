/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: pointer-vector swap.
 */

#include "types.h"

/* Swap the contents of two pointer vectors. */
void func_003FEC90(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
