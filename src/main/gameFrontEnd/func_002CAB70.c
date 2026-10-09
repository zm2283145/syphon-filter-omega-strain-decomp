/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002CAB70(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)(a0 + 600);
    cond = v0 == 0;
    if (cond) goto L002CAB8C;
    v0 = *(unsigned short*)(char*)(v0 + 20);
    v0 = v0 & 8;
    v0 = (unsigned int)0 < (unsigned int)v0;
    goto L002CAB90;
L002CAB8C:;
    v0 = 0;
L002CAB90:;
    goto ret;
ret:
    return v0;
}
