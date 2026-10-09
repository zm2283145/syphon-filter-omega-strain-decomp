/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CB1C0(int);
extern int func_003D9970(int);
extern int Group_RemoveObject(int, int);
extern int func_003D9BA0(int, int);
extern void Group_AddObject(int, int);

int Script_cGroup_Remove(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003D9970(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    tmp4 = func_003CB1C0(tmp3);
    Group_RemoveObject(tmp1, tmp4);
    return 0;
}

int Script_cGroup_AddDup(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003D9970(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    tmp4 = func_003CB1C0(tmp3);
    func_003D9BA0(tmp1, tmp4);
    return 0;
}

int Script_cGroup_Add(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003D9970(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    tmp4 = func_003CB1C0(tmp3);
    Group_AddObject(tmp1, tmp4);
    return 0;
}

void func_003D9960(void) {
}
