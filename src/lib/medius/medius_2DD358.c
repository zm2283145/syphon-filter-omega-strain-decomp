/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_memory_register_callbacks(int, int);

int NetIRegisterMallocFreeCallbacks(void) {
    int a0, a1, v0, v1;

    v0 = rt_memory_register_callbacks(a0, a1);
    v1 = 0 + 22;
    if (v0 == 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
