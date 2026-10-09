/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C3E8[];
extern char D_0048C3F4[];
extern char D_0048C3F8[];
extern char D_0048C3FC[];

int func_002CED28(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3E8;
    cond = v0 == 0;
    if (cond) goto L002CED44;
    v0 = ((int (*)(void))v0)();
L002CED44:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int func_002CED58(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3F8;
    cond = v0 == 0;
    if (cond) goto L002CED74;
    v0 = ((int (*)(void))v0)();
L002CED74:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_002CED88(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3FC;
    cond = v0 == 0;
    if (cond) goto L002CEDA4;
    v0 = ((int (*)(void))v0)();
L002CEDA4:;
    v0 = 0 + 22;
    goto ret;
ret:
    return v0;
}

int func_002CEDB8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3F4;
    cond = v0 == 0;
    if (cond) goto L002CEDD4;
    v0 = ((int (*)(void))v0)();
L002CEDD4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
