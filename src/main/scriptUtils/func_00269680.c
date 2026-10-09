/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F8400[];
extern void Group_AddObject(int, int);
extern int Group_RemoveObject(int, int);
extern int func_0015C120(int);
extern int func_002697E0(int);
extern int func_00269810(int);
extern int func_003CB1D0(void);
extern void func_003D9440(int, int);
extern float func_003D9A00(int);
extern int func_003D9BA0(int, int);

int Script_cNodeList_Randomize(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00269810(tmp0);
    tmp3 = *(int*)((char*)tmp1 + 96);
    func_003D9A00(tmp3);
    return 0;
}

int Script_cNodeList_Remove(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;
    int tmp6;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = func_0015C120(tmp0);
    tmp3 = *(int*)(char*)a0;
    tmp4 = func_00269810(tmp3);
    tmp6 = *(int*)((char*)tmp4 + 96);
    Group_RemoveObject(tmp6, tmp1);
    return 0;
}

int Script_cNodeList_AddDup(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;
    int tmp6;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = func_0015C120(tmp0);
    tmp3 = *(int*)(char*)a0;
    tmp4 = func_00269810(tmp3);
    tmp6 = *(int*)((char*)tmp4 + 96);
    func_003D9BA0(tmp6, tmp1);
    return 0;
}

int Script_cNodeList_Add(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;
    int tmp6;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = func_0015C120(tmp0);
    tmp3 = *(int*)(char*)a0;
    tmp4 = func_00269810(tmp3);
    tmp6 = *(int*)((char*)tmp4 + 96);
    Group_AddObject(tmp6, tmp1);
    return 0;
}

void ScriptType_cNodeList_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F8400;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_002697D0(int a0) {
    return func_002697E0(a0);
}

int func_002697E0(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00269800(int a0) {
    return func_00269810(a0);
}
