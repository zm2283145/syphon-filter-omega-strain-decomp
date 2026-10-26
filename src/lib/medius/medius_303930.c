/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_udp_send_unconnected(int, int, int, int, int);

int rt_p2p_send_to(int a0, int a1, int a2, int a3, int t0) {
    int v0, v1;
    int cond;

    a2 = a2 & 65535;
    t0 = t0 & 65535;
    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L0030395C;
    a0 = *(int*)((char*)a0 + 384);
    v0 = rt_udp_send_unconnected(a0, a1, a2, a3, t0);
    v1 = 0 + 7;
    if (v0 == 0) v1 = 0;
    v0 = v1;
L0030395C:;
    goto ret;
ret:
    return v0;
}
