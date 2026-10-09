/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc and nellymoser_wrapper.c (starts 0x0042C1E0).
 */

#include "types.h"

extern char D_00582630;
extern char D_00582640;
extern char D_00582650;
extern int D_00582668;
extern int D_00582670;
extern int D_00582678;

/* Clears three flags and three counters. */
void func_0042BF90(void) {
    D_00582630 = 0;
    D_00582640 = 0;
    D_00582650 = 0;
    D_00582668 = 0;
    D_00582670 = 0;
    D_00582678 = 0;
}
