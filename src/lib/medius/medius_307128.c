/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int rt_udp_set_aggregation_interval(int a0, int a1) {
    int v0;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L00307138;
    *(int*)((char*)a0 + 60) = a1;
    v0 = 0;
L00307138:;
    goto ret;
ret:
    return v0;
}
