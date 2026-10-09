/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];
extern char D_004EE788[];
extern char D_00555070[];
extern char D_005721C8[];
extern int func_001439B0(int, int);
extern void func_002493C0(int, int);
extern int func_003E1AA0(int, int, int);

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
