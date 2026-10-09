/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00492CE0[];
extern char D_005335D8[];
extern int func_00125368(int);

int func_00357D40(void) {
    int tmp0;

    tmp0 = *(int*)D_00492CE0;
    return tmp0;
}

int func_00357D50(void) {
    int a0, v0;
    int cond;

    v0 = *(int*)(char*)D_005335D8;
    cond = v0 == 0;
    if (cond) goto L00357D74;
    v0 = ((int (*)(void))v0)();
    goto L00357D80;
L00357D74:;
    v0 = func_00125368(a0);
L00357D80:;
    goto ret;
ret:
    return v0;
}
