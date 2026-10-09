/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EEE88[];
extern char D_005061D0[];

void cEquipGogglesMsg_v04(int a0) {
    signed char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(signed char*)((char*)a0 + 36);
    tmp1 = *(int*)D_005061D0;
    *(char*)((char*)tmp1) = tmp0;
    tmp2 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp2 + 1);
}

int cEquipGogglesMsg_v05(void) {
    int tmp0;

    tmp0 = *(int*)D_004EEE88;
    return tmp0;
}
