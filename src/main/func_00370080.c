/*
 * Matched functions (byte-identical with the retail executable).
 * func_00370080 and func_00370090 are Obj370000 virtuals (vtable D_004DF6A0
 * slots 14 and 16).
 */

#include "loose03_types.h"

int func_00370080(void) {
    return 0;
}

void func_00370090(void) {
}

void func_003700A0(void) {
}

void func_003700B0(void) {
}

void func_003700C0(void) {
}

/* table[index] with tag 0x14000000 or-ed in. */
int func_003700D0(int* table, int index) {
    return table[index] | 0x14000000;
}
