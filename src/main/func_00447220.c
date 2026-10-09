/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00585E60[];
extern int func_004505C0(void);

void func_00447220(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = func_004505C0();
    cond = v0 != 0;
    if (cond) goto L00447258;
    a0 = 0 + 1;
    v1 = *(int*)(char*)D_00585E60;
    cond = s0 <= 0;
    *(int*)(char*)(v1 + 388) = a0;
    if (cond) goto L00447258;
    v1 = *(int*)(char*)D_00585E60;
    *(int*)(char*)(v1 + 384) = s0;
L00447258:;
    goto ret;
ret:;
}
