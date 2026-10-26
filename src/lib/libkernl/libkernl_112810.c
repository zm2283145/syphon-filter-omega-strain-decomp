/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int _sceCallCode(int, int);

int sceRemove(int a0) {
    int tmp0;

    tmp0 = _sceCallCode(a0, 6);
    return tmp0;
}
