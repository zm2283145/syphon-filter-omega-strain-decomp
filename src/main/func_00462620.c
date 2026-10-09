/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern int func_00129A70(void* dst, int a1, int a2);
extern int func_00461770(Vec12* v, char* pos, int n, int value);

/* Appends one 12-byte element at the end of the vector. */
int func_00462620(Vec12* v, int value) {
    char* data;
    int count;

    data = v->data;
    count = v->count;
    return func_00461770(v, data + count * 12, 1, value);
}

int* func_00462650(int* self, int a1, int a2) {
    func_00129A70(self, a1, 8);
    self[2] = a2;
    return self;
}
