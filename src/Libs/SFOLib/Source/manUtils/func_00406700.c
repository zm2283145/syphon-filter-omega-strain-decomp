/*
 * Matched functions (byte-identical with the retail executable).
 * manUtils.cc
 */

#include "types.h"

extern void SKL_ConvertSKL(int dst, int text, int a2);
extern int cFileMan_Read_void(int a0);

/* Convert a1 with cFileMan_Read_void and pack the result with SKL_ConvertSKL. */
void SKL_ReadSKL(int dst, int a1, int a2) {
    SKL_ConvertSKL(dst, cFileMan_Read_void(a1), a2);
}
