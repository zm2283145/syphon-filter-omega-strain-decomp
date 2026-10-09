/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA3D0[];
extern char D_004EA3F0[];
extern char D_00555070[];
extern int func_00198F90(int, int, int);
extern int func_00199040(int, int, int);
extern int func_001990F0(int, int, int);
extern int func_003E1AA0(int, int, int);
extern int func_004705D0(int, int);
extern void func_004709C0(int, int, int);
extern void func_00470A70(int, int, int);

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
    return func_003E1AA0((int)D_00555070, a0, a1);
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
