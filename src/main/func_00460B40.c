/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "types.h"

extern int D_004FFC04;
extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);
extern int func_002C9E20(int);
extern int func_0041F090(void* self);

int* func_00460B40(PtrVec* v, int i) {
    return v->data + i;
}

int func_00460B50(PtrVec* v) {
    return v->count;
}

/* Appends one value at the end of the vector. */
int func_00460B60(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

int func_00460B80(void* self) {
    func_0041F090(self);
    return func_002C9E20(D_004FFC04);
}
