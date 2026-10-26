/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_msg_client_update_single(int, int);

int rt_msg_client_iupdate(int a0, int a1) {
    int tmp0;

    tmp0 = rt_msg_client_update_single((a0 & 65535), (a1 & 255));
    return tmp0;
}
