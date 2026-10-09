/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FF128[];
extern char D_004FF130[];
extern char D_004FF138[];
extern char D_004FF148[];
extern char D_004FF168[];
extern char D_004FF178[];
extern char D_004FF198[];
extern char D_004FF1B0[];
extern char D_004FF1B8[];
extern char D_004FF1C0[];
extern char D_004FF1C8[];
extern char D_004FF1D0[];
extern char D_004FF1D8[];
extern char D_004FF1E8[];
extern char D_004FF1F0[];
extern char D_004FF210[];
extern char D_004FF218[];
extern char D_004FF220[];
extern char D_004FF228[];
extern char D_004FF240[];
extern char D_004FF248[];
extern char D_004FF250[];
extern char D_004FF258[];
extern int func_0015C100(int);
extern int func_003C8C50(void);
extern int GObj_IdentityA(int);
extern void func_003D9440(int, int);

int func_0026ECF0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026ED00(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF258;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026ED30(void) {
    return (int)D_004FF250;
}

int func_0026ED40(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF250;
    return tmp0;
}

void func_0026ED50(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF248;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026ED70(void) {
    return (int)D_004FF240;
}

int func_0026ED80(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF240;
    return tmp0;
}

int func_0026ED90(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(unsigned char*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_0026EDB0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026EDC0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF228;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026EDF0(void) {
    return (int)D_004FF220;
}

int func_0026EE00(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF220;
    return tmp0;
}

void func_0026EE10(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF218;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EE30(void) {
    return (int)D_004FF210;
}

int func_0026EE40(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF210;
    return tmp0;
}

int func_0026EE50(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 48);
}

int func_0026EE60(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 44);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_0026EE80(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void func_0026EEA0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1F0;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EEC0(void) {
    return (int)D_004FF1E8;
}

int func_0026EED0(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1E8;
    return tmp0;
}

int func_0026EEE0(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 40);
}

void func_0026EEF0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1D8;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF10(void) {
    return (int)D_004FF1D0;
}

int func_0026EF20(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1D0;
    return tmp0;
}

void func_0026EF30(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1C8;
    tmp1 = *(int*)D_004FF198;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF50(void) {
    return (int)D_004FF1C0;
}

int func_0026EF60(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1C0;
    return tmp0;
}

void func_0026EF70(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF1B8;
    tmp1 = *(int*)D_004FF198;
    func_003D9440(tmp0, tmp1);
}

int func_0026EF90(void) {
    return (int)D_004FF1B0;
}

int func_0026EFA0(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF1B0;
    return tmp0;
}

int func_0026EFB0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return func_0015C100(tmp1);
}

void func_0026EFC0(void) {
}

int func_0026EFD0(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF198;
    return tmp0;
}

int func_0026EFE0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

int func_0026EFF0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026F000(void) {
}

int func_0026F010(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF178;
    return tmp0;
}

void func_0026F020(void) {
}

int func_0026F030(void) {
    return (int)D_004FF168;
}

int func_0026F040(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF168;
    return tmp0;
}

int func_0026F050(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 40);
}

int func_0026F060(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return GObj_IdentityA(tmp1);
}

void func_0026F070(void) {
}

int func_0026F080(void) {
    return (int)D_004FF148;
}

int func_0026F090(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF148;
    return tmp0;
}

void func_0026F0A0(void) {
}

int func_0026F0B0(void) {
    return (int)D_004FF138;
}

int func_0026F0C0(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF138;
    return tmp0;
}

void func_0026F0D0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF130;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026F0F0(void) {
    return (int)D_004FF128;
}

int func_0026F100(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF128;
    return tmp0;
}
