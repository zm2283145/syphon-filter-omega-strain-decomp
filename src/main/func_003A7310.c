/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int snd_SendIOPCommandNoWait(int, int, int, int, int);

int func_003A7310(void) {
    return snd_SendIOPCommandNoWait(52, 0, 0, 0, 0);
}

void func_003A7330(int a0, int a1, int a2) {
    int loc[4];
    int a3, t0, v0;

    a3 = 0;
    t0 = 0;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 98;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 12;
    a2 = (int)loc;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
