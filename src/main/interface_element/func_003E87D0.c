/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"

/* Declared as char[] and accessed through casts: typed scalars let the
 * compiler sink the counter load below the flag store, which breaks the match. */
extern char D_00538C64[];   /* int counter */
extern char D_00538C68[];   /* char flag */

/* Decrement the global counter and set the companion flag. */
void func_003E87D0(void) {
    int count;

    count = *(int*)D_00538C64;
    *(char*)D_00538C68 = 1;
    *(int*)D_00538C64 = count - 1;
}
