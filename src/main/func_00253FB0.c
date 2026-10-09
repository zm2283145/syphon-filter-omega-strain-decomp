/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern char D_005716C0[];

int func_00253FB0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_004FFD30;
    v0 = *(int*)(char*)(v0 + 184);
    cond = v0 == 0;
    if (cond) goto L00253FCC;
    v0 = v0 + 992;
    goto L00253FD4;
L00253FCC:;
    v0 = (int)D_005716C0;
L00253FD4:;
    goto ret;
ret:
    return v0;
}
