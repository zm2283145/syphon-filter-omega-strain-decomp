/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EEEA0[];
extern char D_005061D0[];

void cNetSetFlagMsg_v04(int a0) {
    signed char tmp0;
    int tmp1;
    int tmp2;
    signed char tmp3;
    int tmp4;
    int tmp5;

    tmp0 = *(signed char*)((char*)a0 + 37);
    tmp1 = *(int*)D_005061D0;
    *(char*)((char*)tmp1) = tmp0;
    tmp2 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp2 + 1);
    tmp3 = *(signed char*)((char*)a0 + 36);
    tmp4 = *(int*)D_005061D0;
    *(char*)((char*)tmp4) = tmp3;
    tmp5 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp5 + 1);
}

int cNetSetFlagMsg_v05(void) {
    int tmp0;

    tmp0 = *(int*)D_004EEEA0;
    return tmp0;
}
