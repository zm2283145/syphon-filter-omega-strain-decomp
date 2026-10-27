/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_parse_register(int, int, int);

int NetIRegisterMessage(void) {
    int a0, a1, a2, v0, v1;

    v0 = rt_parse_register(a0, a1, a2);
    v1 = 0 + 30;
    if (v0 == 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
