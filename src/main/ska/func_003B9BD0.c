/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

unsigned int D_004BCEE8[2] = { 0x0, 0x0 };
extern signed char D_00542C90;

/* Lazily initialised constant: 0x1800000 - 1 (guarded function-local static). */
int func_003B9BD0(void) {
    int size[1];
    int ref;

    if (D_00542C90 == 0) {
        ref = (int)size; /* value is read back through its address (inlined helper) */
        size[0] = 0x1800000;
        ref = *(int*)ref;
        D_00542C90 = 1;
        (*(int*)D_004BCEE8) = ref - 1;
    }
    return (*(int*)D_004BCEE8);
}
