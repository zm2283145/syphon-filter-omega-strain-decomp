/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Insck_Send(int, int, int, int);
extern int Insck_Sendto(int, int, int, int, int);

int func_0045AD98(int a0, int a1, int a2, int a3) {
    int tmp0;

    tmp0 = Insck_Send(a0, a1, a2, a3);
    return tmp0;
}

int func_0045ADB8(int a0, int a1, int a2, int a3, int t0) {
    int tmp0;

    tmp0 = Insck_Sendto(a0, a1, a2, a3, t0);
    return tmp0;
}
