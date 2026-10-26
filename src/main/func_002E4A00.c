/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int NetUpdateAll(int arg);
extern int NetProcessEchoRequests(int arg);

void NetITick(void) {
    if (NetUpdateAll(0) == 0) {
        NetProcessEchoRequests(0);
    }
}
