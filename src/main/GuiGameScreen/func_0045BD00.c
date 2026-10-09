/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0045BD00(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)(a0 + 224);
    cond = v0 == 0;
    if (cond) goto L0045BD1C;
    v0 = *(unsigned short*)(char*)(v0 + 20);
    v0 = v0 & 2;
    v0 = (unsigned int)0 < (unsigned int)v0;
    goto L0045BD20;
L0045BD1C:;
    v0 = 0;
L0045BD20:;
    goto ret;
ret:
    return v0;
}
