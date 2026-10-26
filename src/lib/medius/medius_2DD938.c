/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005880A0[];
extern int NetIIpStringToBinary(int, int);

int NetIGetCurrentUDPSourceBinaryIP(int a0) {
    int a1, v0;
    int cond;

    v0 = 0 + 23;
    cond = a0 == 0;
    if (cond) goto L002DD958;
    a1 = (int)D_005880A0;
    v0 = NetIIpStringToBinary(a0, a1);
    v0 = 0;
L002DD958:;
    goto ret;
ret:
    return v0;
}
