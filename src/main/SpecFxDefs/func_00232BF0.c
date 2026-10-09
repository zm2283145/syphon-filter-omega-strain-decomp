/*
 * Matched functions (byte-identical with the retail executable).
 * Float-argument forwarder.
 */

#include "types.h"

extern int func_00232C00(int, int, float, float, float, float);

/* Forwards to func_00232C00 unchanged. */
int func_00232BF0(int a0, int a1, float f0, float f1, float f2, float f3) {
    return func_00232C00(a0, a1, f0, f1, f2, f3);
}
