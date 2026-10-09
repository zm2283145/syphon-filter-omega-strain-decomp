/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EEEF0[];
extern char D_005061D0[];
extern void func_00282020(int);

void cNetMeleeAttackMsg_v04(int a0) {
    int tmp0;
    signed char tmp3;
    int tmp4;
    int tmp5;

    tmp0 = *(int*)((char*)a0 + 36);
    func_00282020(tmp0);
    tmp3 = *(signed char*)((char*)a0 + 40);
    tmp4 = *(int*)D_005061D0;
    *(char*)((char*)tmp4) = tmp3;
    tmp5 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp5 + 1);
}

int cNetMeleeAttackMsg_v05(void) {
    int tmp0;

    tmp0 = *(int*)D_004EEEF0;
    return tmp0;
}
