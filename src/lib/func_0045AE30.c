/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Insck_Socket(int, int);
extern int Insck_Close(int);

int func_0045AE30(int a0) {
    int tmp0;

    tmp0 = Insck_Close(a0);
    return tmp0;
}

int func_0045AE50(int a0, int a1) {
    int tmp0;

    tmp0 = Insck_Socket(a0, a1);
    return tmp0;
}
