/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern int strncpy(void* dst, int a1, int a2);
extern int std_vector_imp_tQuip_insert(Vec12* v, char* pos, int n, int value);

/* Appends one 12-byte element at the end of the vector. */
int cArray_tQuip_PushBackActual(Vec12* v, int value) {
    char* data;
    int count;

    data = v->data;
    count = v->count;
    return std_vector_imp_tQuip_insert(v, data + count * 12, 1, value);
}

int* cQuipList_tQuip_ctor(int* self, int a1, int a2) {
    strncpy(self, a1, 8);
    self[2] = a2;
    return self;
}
