#include "types.h"

extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
extern int func_00127358(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

int func_00311188(int a0) {
    int a1, a2, a3, t0, t1, t2, t3, v0;
    float f12, f13, f14, f15, f16, f17, f18, f19;
    int cond;

    cond = a0 != 0;
    if (cond) goto L003111C0;
    a0 = (int)D_004B0DE0;
    a1 = (int)D_004B0E18;
    a3 = (int)D_004B0F28;
    a2 = 0 + 389;
    v0 = func_00127358(a0, a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    v0 = 0;
    goto L003111D4;
L003111C0:;
    v0 = 0x10000;
    v0 = v0 + a0;
    v0 = *(int*)((char*)v0 + -31728);
    v0 = v0 ^ 26;
    v0 = (unsigned int)v0 < (unsigned int)1;
L003111D4:;
    goto ret;
ret:
    return v0;
}
