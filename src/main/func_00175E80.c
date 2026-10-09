/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];
extern char D_004EE788[];
extern char D_004EE790[];
extern char D_00555070[];
extern char D_005721C8[];
extern int func_001439B0(int, int);
extern int func_001450C0(void);
extern int func_0014A690(int);
extern void func_001B8750(int, int);
extern int func_0022DE00(void);
extern int func_0022F170(void);
extern int func_0022F1F0(void);
extern void func_002493C0(int, int);
extern int func_003CC800(int);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);
extern int func_004080E0(void);

int func_00175E80(void) {
    return 0;
}

int func_00175E90(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 4);
    func_0014A690(tmp0);
    return 0;
}

int func_00175EB0(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    tmp2 = *(int*)((char*)tmp1 + 48);
    func_001B8750(tmp2, ((unsigned int)(0) < (unsigned int)(tmp0)));
    return 0;
}

int func_00175EE0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return func_003CC800(tmp1);
}

int func_00175EF0(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp12;
    int tmp14;
    int tmp15;
    int tmp18;
    int tmp20;
    int tmp21;
    int tmp24;
    int tmp26;
    int tmp27;
    int tmp28;

    tmp0 = func_0022F170();
    tmp2 = *(int*)D_004EE790;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_0022DE00();
    tmp8 = *(int*)D_004EE790;
    tmp9 = *(int*)(char*)tmp6;
    func_003D9400(tmp8, tmp9);
    tmp12 = func_0022F1F0();
    tmp14 = *(int*)D_004EE790;
    tmp15 = *(int*)(char*)tmp12;
    func_003D9400(tmp14, tmp15);
    tmp18 = func_004080E0();
    tmp20 = *(int*)D_004EE790;
    tmp21 = *(int*)(char*)tmp18;
    func_003D9400(tmp20, tmp21);
    tmp24 = func_001450C0();
    tmp26 = *(int*)D_004EE790;
    tmp27 = *(int*)(char*)tmp24;
    tmp28 = func_003D9400(tmp26, tmp27);
    return tmp28;
}

int func_00175F80(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_00175FA0(void* self) {
    return self;
}

int func_00175FB0(void) {
    return (int)D_004EE788;
}

int func_00175FC0(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE788;
    return tmp0;
}

int func_00175FD0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

void func_00175FF0(int a0) {
    int a1, s0, s1, v0, v1;
    int cond;

    s0 = *(int*)(char*)(a0 + 48);
    cond = s0 == 0;
    s1 = a0;
    if (cond) goto L00176040;
    a0 = *(int*)(char*)(s0 + 76);
    v1 = *(int*)(char*)D_0049D010;
    cond = a0 != v1;
    if (cond) goto L00176040;
    a0 = *(int*)(char*)(s0 + 13604);
    v0 = func_001439B0(a0, a1);
    v1 = *(unsigned char*)(char*)D_005721C8;
    cond = v1 == 0;
    a0 = s1 + 80;
    if (cond) goto L00176040;
    a1 = s0;
    func_002493C0(a0, a1);
L00176040:;
    goto ret;
ret:;
}
