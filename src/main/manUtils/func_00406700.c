/*
 * Matched functions (byte-identical with the retail executable).
 * manUtils.cc
 */

#include "types.h"

extern void Appearance_PackText(int dst, int text, int a2);
extern int func_0036DC60(int a0);

/* Convert a1 with func_0036DC60 and pack the result with Appearance_PackText. */
void func_00406700(int dst, int a1, int a2) {
    Appearance_PackText(dst, func_0036DC60(a1), a2);
}
