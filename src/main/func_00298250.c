/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048B7A0[];
extern char D_0048B7A4[];
extern char D_0048B7A8[];
extern char D_0048B7C8[];
extern char D_0048B7E8[];
extern char D_0048B808[];
extern char D_0048B828[];
extern char D_0048B848[];
extern int func_00294300(int, int);
extern void func_00294AB0(int);
extern int func_00295090(int, int, int);
extern int func_002952C0(int);
extern void func_00298310(void);
extern void func_00298360(int);

int func_00298250(int a0) {
    int a1, a2, s0, v0, v1;
    int cond;

    s0 = a0;
    func_00298360(a0);
    v1 = *(int*)(char*)(s0 + 460);
    v0 = 0 + -1;
    cond = v1 != v0;
    a0 = s0;
    if (cond) goto L00298288;
    func_00294AB0(a0);
    a0 = s0;
    v0 = func_002952C0(a0);
    *(int*)(char*)(s0 + 460) = v0;
L00298288:;
    a1 = *(int*)(char*)(s0 + 460);
    a0 = s0;
    a2 = 0;
    v0 = func_00295090(a0, a1, a2);
    a1 = *(signed char*)(char*)(s0 + 468);
    a0 = s0;
    v0 = func_00294300(a0, a1);
    goto ret;
ret:
    return v0;
}

void func_002982C0(int a0) {
    func_00298310();
    *(int*)((char*)a0 + 460) = -1;
    *(int*)((char*)a0 + 720) = 0;
    *(int*)((char*)a0 + 724) = 0;
    *(int*)((char*)a0 + 728) = 0;
    *(int*)((char*)a0 + 732) = 0;
    *(int*)((char*)a0 + 736) = 0;
    *(int*)((char*)a0 + 740) = 0;
}

void func_00298310(void) {
    *(char*)D_0048B7A0 = 0;
    *(char*)D_0048B7A8 = 0;
    *(int*)D_0048B7A4 = -1;
    *(char*)D_0048B7C8 = 0;
    *(char*)D_0048B7E8 = 0;
    *(char*)D_0048B808 = 0;
    *(char*)D_0048B828 = 0;
    *(char*)D_0048B848 = 0;
}
