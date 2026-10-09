/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA3D0[];
extern char D_004EA3F0[];
extern char D_004EA3F8[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_0016AD70(void);
extern int func_00198F90(int, int, int);
extern int func_00199040(int, int, int);
extern int func_001990F0(int, int, int);
extern int func_00210CB0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_004080E0(void);
extern int func_004705D0(int, int);
extern void func_004709C0(int, int, int);
extern void func_00470A70(int, int, int);

int func_0014A600(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp12;
    int tmp13;
    int tmp16;
    int tmp18;
    int tmp19;
    int tmp20;

    tmp0 = func_0016AD70();
    tmp2 = *(int*)D_004EA3F8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_00210CB0();
    tmp8 = *(int*)D_004EA3F8;
    tmp9 = *(int*)(char*)tmp6;
    func_003D9400(tmp8, tmp9);
    tmp12 = *(int*)D_004EA3F8;
    tmp13 = *(int*)D_004EA3D0;
    func_003D9400(tmp12, tmp13);
    tmp16 = func_004080E0();
    tmp18 = *(int*)D_004EA3F8;
    tmp19 = *(int*)(char*)tmp16;
    tmp20 = func_003D9400(tmp18, tmp19);
    return tmp20;
}

int func_0014A670(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_0014A690(void* self) {
    return self;
}

int func_0014A6A0(void) {
    return (int)D_004EA3F0;
}

int func_0014A6B0(void) {
    int tmp0;

    tmp0 = *(int*)D_004EA3F0;
    return tmp0;
}

int func_0014A6C0(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int func_0014A6E0(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_0014A6F0(void) {
}

int func_0014A700(void) {
    int tmp0;

    tmp0 = *(int*)D_004EA3D0;
    return tmp0;
}

int func_0014A710(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)tmp0 + 13608);
    return func_004705D0(tmp1, a1);
}

void func_0014A720(int a0, int a1, int a2) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)tmp0 + 13608);
    func_004709C0(tmp1, a1, a2);
}

void func_0014A730(int a0, int a1, int a2) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)tmp0 + 13608);
    func_00470A70(tmp1, a1, a2);
}

int func_0014A740(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_001990F0(tmp0, a1, 0);
}

int func_0014A750(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_00199040(tmp0, a1, 0);
}

int func_0014A760(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_00198F90(tmp0, a1, 0);
}
