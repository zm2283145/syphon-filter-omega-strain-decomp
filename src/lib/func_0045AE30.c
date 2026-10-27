/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceInsockSocket(int, int);
extern int sceInsockShutdown(int);

int sceNetGlueShutdown(int a0) {
    int tmp0;

    tmp0 = sceInsockShutdown(a0);
    return tmp0;
}

int sceNetGlueSocket(int a0, int a1) {
    int tmp0;

    tmp0 = sceInsockSocket(a0, a1);
    return tmp0;
}
