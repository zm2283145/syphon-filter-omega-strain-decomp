#include "types.h"

extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
extern int func_00127358(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int func_00311418(int, int, int);
extern int func_00312A90(int);

int func_00310F88(int a0, int a1, int a2, int a3) {
    int s0, s1, t0, t1, t2, t3, v0, v1;
    float f12, f13, f14, f15, f16, f17, f18, f19;
    int cond;

    v0 = 0;
    s0 = a0;
    s1 = a3 & 255;
    v1 = a1;
    cond = s0 != 0;
    a3 = a2;
    if (cond) goto L00310FD8;
    a0 = (int)D_004B0DE0;
    a1 = (int)D_004B0E18;
    a3 = (int)D_004B0F28;
    a2 = 0 + 300;
    v0 = func_00127358(a0, a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    v0 = 0 + 3;
    goto L00311000;
L00310FD8:;
    cond = v1 == 0;
    if (cond) goto L00310FF0;
    cond = a3 == 0;
    if (cond) goto L00310FF0;
    v0 = func_00311418(a0, a1, a2);
L00310FF0:;
    if (s1 == 0) {
    goto L00311004;
    }
    a0 = s0;
    v0 = func_00312A90(a0);
L00311000:;
L00311004:;
    goto ret;
ret:
    return v0;
}
