/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_upnp_disable_natservice_heartbeat(int);

int rt_udp_disable_nat_service_heartbeat(int a0) {
    int v0;
    int cond;

    v0 = 0 + 2;
    cond = a0 == 0;
    if (cond) goto L003076D4;
    a0 = *(int*)((char*)a0 + 8);
    v0 = rt_upnp_disable_natservice_heartbeat(a0);
    v0 = 0;
L003076D4:;
    goto ret;
ret:
    return v0;
}
