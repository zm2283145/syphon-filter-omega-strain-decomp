/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceInsockSend(int, int, int, int);
extern int sceInsockSendto(int, int, int, int, int);

int sceNetGlueSend(int a0, int a1, int a2, int a3) {
    int tmp0;

    tmp0 = sceInsockSend(a0, a1, a2, a3);
    return tmp0;
}

int sceNetGlueSendto(int a0, int a1, int a2, int a3, int t0) {
    int tmp0;

    tmp0 = sceInsockSendto(a0, a1, a2, a3, t0);
    return tmp0;
}
