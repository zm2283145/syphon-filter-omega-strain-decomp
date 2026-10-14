/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002F7EA0(int a0, int a1) {
    int v0;
    int cond;

    cond = a0 == 0;
    if (cond) goto L002F7ED0;
    *(int*)((char*)a1 + 4) = 0;
    v0 = *(int*)((char*)a0 + 8);
    if (v0 == 0) {
    *(int*)((char*)a0 + 8) = a1;
    goto L002F7EC8;
    }
    v0 = *(int*)((char*)a0 + 12);
    *(int*)(char*)a1 = v0;
    *(int*)((char*)v0 + 4) = a1;
    goto L002F7ECC;
L002F7EC8:;
    *(int*)(char*)a1 = 0;
L002F7ECC:;
    *(int*)((char*)a0 + 12) = a1;
L002F7ED0:;
    goto ret;
ret:
    return v0;
}
