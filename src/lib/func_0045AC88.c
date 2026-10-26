/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Insck_Listen(int, int);

int sceNetGlueListen(int a0, int a1) {
    int tmp0;

    tmp0 = Insck_Listen(a0, a1);
    return tmp0;
}
