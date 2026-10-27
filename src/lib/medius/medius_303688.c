/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_udp_event_process(int);

int rt_p2p_tick(int a0) {
    int v0, v1;
    int cond;

    v0 = 0 + 2;
    cond = a0 == 0;
    if (cond) goto L003036AC;
    a0 = *(int*)((char*)a0 + 384);
    v0 = rt_udp_event_process(a0);
    v1 = 0 + 7;
    if (v0 == 0) v1 = 0;
    v0 = v1;
L003036AC:;
    goto ret;
ret:
    return v0;
}
