/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D91C0[];
extern char D_005435A8[];
extern int Vec4_Assign(int, int);
extern int func_001325E0(int, int);
extern int func_00139B00(int, int);
extern int func_00139BA0(int, int);
extern int func_00139BB0(int, int);
extern int func_003C9E30(int, int);

int func_0013A9A0(int a0, int a1) {
    int s0, s1, s2, v0, v1;

    s2 = a0;
    s1 = a1;
    a1 = (int)D_005435A8;
    v0 = func_003C9E30(a0, a1);
    s0 = s2 + 48;
    v0 = (int)D_004D91C0;
    a0 = s0 + 16;
    *(int*)(char*)s2 = v0;
    a1 = s1 + 16;
    v0 = *(unsigned char*)(char*)s1;
    *(char*)(char*)(s2 + 48) = v0;
    v0 = Vec4_Assign(a0, a1);
    a0 = s0 + 32;
    a1 = s1 + 32;
    v0 = func_00139B00(a0, a1);
    v1 = *(int*)(char*)(s1 + 144);
    v0 = s2;
    *(int*)(char*)(s0 + 144) = v1;
    goto ret;
ret:
    return v0;
}

void func_0013AA20(char* self, int value) {
    *(int*)(self + 144) = value;
}

int func_0013AA30(int a0, int a1) {
    unsigned char tmp8;
    int tmp11;
    unsigned char tmp13;
    unsigned char tmp14;

    func_001325E0((a0 + 32), a1);
    func_001325E0((a0 + 48), (a1 + 16));
    func_001325E0((a0 + 64), (a1 + 32));
    func_001325E0((a0 + 80), (a1 + 48));
    tmp8 = *(unsigned char*)((char*)a1 + 80);
    *(char*)((char*)a0 + 112) = tmp8;
    func_00139BB0((a0 + 96), (a1 + 64));
    tmp11 = func_00139BA0((a0 + 128), (a1 + 96));
    tmp13 = *(unsigned char*)((char*)a1 + 81);
    *(char*)((char*)a0 + 113) = tmp13;
    tmp14 = *(unsigned char*)((char*)a1 + 82);
    *(char*)((char*)a0 + 114) = tmp14;
    return tmp11;
}
