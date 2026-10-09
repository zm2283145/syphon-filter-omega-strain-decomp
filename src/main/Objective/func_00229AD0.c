/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048AB20[];
extern char D_004F7560[];
extern void func_00229AF0(int);
extern void func_00229B20(int);

int Script_SetObjectivesHeaderFont(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    func_00229AF0(tmp0);
    return 0;
}

void func_00229AF0(int a0) {
    *(char*)D_004F7560 = a0;
}

int Script_SetObjectivesFont(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    func_00229B20(tmp0);
    return 0;
}

void func_00229B20(int a0) {
    *(char*)D_0048AB20 = a0;
}

int cObjective_v04(void) {
    return 1;
}
