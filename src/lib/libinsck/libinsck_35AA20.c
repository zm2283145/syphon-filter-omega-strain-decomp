/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int _get_peer_or_sock_name(int, int, int, int);

int sceInsockGetsockname(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = _get_peer_or_sock_name(a0, a1, a2, 0);
    return tmp0;
}

int sceInsockGetpeername(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = _get_peer_or_sock_name(a0, a1, a2, 1);
    return tmp0;
}
