/*
 * Matched functions (byte-identical with the retail executable).
 * cXform_GetNode_void_2 and cXform_SetParent are Obj370000 virtuals (vtable D_004DF6A0
 * slots 14 and 16).
 */

#include "loose03_types.h"

int cXform_GetNode_void_2(void) {
    return 0;
}

void cXform_SetParent(void) {
}

void cXform_RemoveParent(void) {
}

void cXform_AddChild(void) {
}

void cXform_RemoveChild(void) {
}

/* table[index] with tag 0x14000000 or-ed in. */
int cVU1Man_GetMSCAL(int* table, int index) {
    return table[index] | 0x14000000;
}
