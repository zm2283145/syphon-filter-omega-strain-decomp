/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

unsigned int D_0048C3E8[1] = { 0x0 };
extern char D_0048C3F4[];
extern char D_0048C3F8[];
extern char D_0048C3FC[];

int GlobalMediusTypeServerCreateGameCallback(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)((char*)D_0048C3E8);
    cond = v0 == 0;
    if (cond) goto L002CED44;
    v0 = ((int (*)(void))v0)();
L002CED44:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int GlobalMediusTypeServerCreateGameOnMeCallback(void) {
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

int GlobalMediusTypeServerEndGameOnMeCallback(void) {
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

int GlobalMediusTypeServerWorldStatusCallback(void) {
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
