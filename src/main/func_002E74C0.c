/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int NetFreeRemoteObject(int value);

int DeleteNetObjectPacketHandler(int a0, int a1, int a2, unsigned short* a3) {
    int result = -1;

    if (a3 != 0) {
        NetFreeRemoteObject(*a3);
        result = 2;
    }
    return result;
}
