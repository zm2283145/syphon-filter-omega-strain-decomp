/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Appends one value at the end of the vector. */
int func_004637B0(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}
