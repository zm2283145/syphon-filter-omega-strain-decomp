/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "types.h"

extern int D_004FFC04;
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);
extern int cGameFrontEnd_CloseZeusHog(int);
extern int GuiWidget_onRemove(void* self);

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
    return std_vector_pod_int_insert(v, data + count, 1, value);
}

int GuiEndGameAwards_onRemove(void* self) {
    GuiWidget_onRemove(self);
    return cGameFrontEnd_CloseZeusHog(D_004FFC04);
}
