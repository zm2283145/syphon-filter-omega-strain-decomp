/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005724B0[];
extern int func_002EAD30(int);
extern int func_002EC4F8(void);
extern int func_00429660(int, int);

int func_0042AEC0(void) {
    int a0, v0;
    int cond;

    v0 = 0 + 3;
    a0 = (int)func_00429660;
    *(char*)(char*)D_005724B0 = v0;
    v0 = func_002EAD30(a0);
    cond = v0 != 0;
    if (cond) goto L0042AEF0;
    v0 = func_002EC4F8();
L0042AEF0:;
    goto ret;
ret:
    return v0;
}
