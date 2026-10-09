/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506228[];
extern int GObj_IdentityA(int);

int Script_cBeamMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_00282860(void) {
}

int cBeamMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_00506228;
    return tmp0;
}
