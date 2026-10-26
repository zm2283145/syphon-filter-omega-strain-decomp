/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceSifMBindRpcParam(int, int, int, int, int, int);

int sceSifMBindRpc(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceSifMBindRpcParam(a0, a1, a2, 2048, 8192, 32);
    return tmp0;
}
