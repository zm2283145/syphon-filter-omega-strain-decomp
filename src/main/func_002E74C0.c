/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002DEA68(int);

int func_002E74C0(int a0, int a1, int a2, int a3) {
    int v0;
    int cond;

    v0 = 0 + -1;
    cond = a3 == 0;
    if (cond) goto L002E74DC;
    a0 = *(unsigned short*)(char*)a3;
    v0 = func_002DEA68(a0);
    v0 = 0 + 2;
L002E74DC:;
    goto ret;
ret:
    return v0;
}
