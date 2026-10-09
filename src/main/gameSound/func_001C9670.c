/*
 * Matched functions (byte-identical with the retail executable).
 * Thin wrappers around the low-level sound library.
 */

#include "types.h"
#include "gameSound_types.h"

extern void func_003A7310(void);
extern void func_003A7FE0(void);
extern void func_003A80F0(int a0);
extern int func_003A85E0(void);

void func_001C9670(int unused, int a1) {
    func_003A80F0(a1);
}

/* Calls two library routines, then polls func_003A85E0 until it returns 0. */
void func_001C9680(void) {
    func_003A7FE0();
    func_003A7310();
    while (func_003A85E0() != 0) {
    }
}
