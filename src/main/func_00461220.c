/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern char D_004C25C0[];
extern char D_004F2CC0[];

/* Address of 12-byte element `i`. */
char* func_00461220(Vec12* v, int i) {
    return v->data + i * 12;
}

int func_00461240(Vec12* v) {
    return v->count;
}

char* func_00461250(void) {
    return D_004F2CC0;
}

char* func_00461260(void) {
    return D_004C25C0;
}
