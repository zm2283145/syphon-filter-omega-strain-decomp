/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_p2p_generic_disconnect(int, int);

int rt_p2p_handle_reset_event(int a0, int a1) {
    int tmp0;

    tmp0 = rt_p2p_generic_disconnect(a0, a1);
    return tmp0;
}

int rt_p2p_handle_closed_event(int a0, int a1) {
    int tmp0;

    tmp0 = rt_p2p_generic_disconnect(a0, a1);
    return tmp0;
}

int rt_p2p_handle_error_event(int a0, int a1) {
    int tmp0;

    tmp0 = rt_p2p_generic_disconnect(a0, a1);
    return tmp0;
}
