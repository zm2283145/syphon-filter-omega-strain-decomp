/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005721A0[];
extern int Event_PackHeader(int, int, int, int, int, int, int);

int func_00429150(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int tmp2;

    Event_PackHeader(a0, a1, a2, a3, t0, t1, t2);
    tmp2 = *(int*)D_005721A0;
    *(int*)((char*)a2) = tmp2;
    return 8;
}
