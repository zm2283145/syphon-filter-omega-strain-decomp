/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055D4A0[];
extern int Event_PackHeader(int, int, int, int, int, int, int);

int cDisableMsg_v02(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int tmp2;
    int tmp3;

    Event_PackHeader(a0, a1, a2, a3, t0, t1, t2);
    tmp2 = *(int*)((char*)a0 + 36);
    *(int*)((char*)t2 + 8) = tmp2;
    tmp3 = *(int*)D_0055D4A0;
    *(int*)((char*)a2) = tmp3;
    return 12;
}
