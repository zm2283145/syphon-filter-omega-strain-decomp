/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004C2460[];
extern int func_00414790(void);
extern int func_004147A0(void);
extern void func_00414AC0(int, int, int);
extern int func_00419530(int, int);
extern int func_0041EFA0(int);
extern int func_0041F960(int);
extern int func_00441A10(int);

void func_0045F300(int a0) {
    int tmp0;

    tmp0 = func_004147A0();
    func_00414AC0(tmp0, a0, 0);
}

int func_0045F340(int a0) {
    int tmp2;

    func_0041EFA0(a0);
    *(char*)((char*)a0 + 76) = 2;
    tmp2 = func_00441A10(a0);
    return tmp2;
}

void func_0045F380(int a0) {
    int a1, a2, s0, s1, v0;
    int cond;

    s1 = a0;
    a0 = (int)D_004C2460;
    v0 = func_0041F960(a0);
    s0 = v0;
    cond = s0 == 0;
    if (cond) goto L0045F3D8;
    v0 = func_00414790();
    a0 = v0;
    a1 = s0;
    v0 = func_00419530(a0, a1);
    v0 = func_004147A0();
    a1 = s1;
    a2 = s0;
    a0 = v0;
    func_00414AC0(a0, a1, a2);
L0045F3D8:;
    goto ret;
ret:;
}
