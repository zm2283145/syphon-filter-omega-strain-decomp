/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C3DC[];
extern char D_0048C3F0[];

int func_002CEF30(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3F0;
    cond = v0 == 0;
    if (cond) goto L002CEF4C;
    v0 = ((int (*)(void))v0)();
L002CEF4C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_002CEF60(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3DC;
    cond = v0 == 0;
    if (cond) goto L002CEF7C;
    v0 = ((int (*)(void))v0)();
L002CEF7C:;
    v0 = 0 + 180;
    goto ret;
ret:
    return v0;
}
