/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54F0[];
extern char D_004F5540[];
extern char D_004F5548[];
extern char D_004F5610[];
extern char D_00555070[];
extern int Lift_OpenDoors(int);
extern int Lift_CloseDoors(int);
extern int func_00214BD0(int);
extern int Lift_SeekFloor(int, int, int, int);
extern int func_00214FA0(int);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int ScriptFilter_Dispatch(int, int, int);

int func_00211000(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    func_00214BD0(tmp0);
    return 0;
}

int func_00211020(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 296);
    v0 = *(int*)(char*)v0;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00211040(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 296);
    v0 = *(int*)(char*)(v0 + 32);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00211060(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 136);
    v0 = 0 < v0;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00211080(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00214FA0(tmp0);
    return (tmp1 & 255);
}

int func_002110A0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Lift_CloseDoors(tmp0);
    return (tmp1 & 255);
}

int func_002110C0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Lift_OpenDoors(tmp0);
    return (tmp1 & 255);
}

int func_002110E0(int a0) {
    int loc[1];
    int a1, a2, a3, v0, v1;

    a3 = 0;
    v1 = *(int*)(char*)(a0 + 8);
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = (unsigned int)0 < (unsigned int)v1;
    v0 = Lift_SeekFloor(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00211120(void) {
    int tmp0;
    int tmp1;
    int tmp4;
    int tmp5;
    int tmp6;

    tmp0 = *(int*)D_004F5548;
    tmp1 = *(int*)D_004F54F0;
    func_003D9440(tmp0, tmp1);
    tmp4 = *(int*)D_004F5548;
    tmp5 = *(int*)D_004F5610;
    tmp6 = func_003D9400(tmp4, tmp5);
    return tmp6;
}

int Lift_GetScriptType(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5540;
    return tmp0;
}

int Lift_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Script_Mover_SetSpeed(Args* a) {
    union { int i; float f; } u;
    u.i = a->arg1;
    a->obj->speed = u.f;
    return 0;
}
