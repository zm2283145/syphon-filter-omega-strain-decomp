#include "types.h"

extern char D_0055A1E0[];
extern int func_003FF330(int, int, int, int, int, int, int);

int func_003E61F0(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int s0, s1, s2, s3, v0;
    float f0;
    int cond;

    v0 = (unsigned int)t1 < (unsigned int)16;
    s3 = a0;
    s2 = a2;
    s1 = t2;
    cond = v0 != 0;
    s0 = 0 + -1;
    if (cond) goto L003E6250;
    cond = s1 == 0;
    a2 = 0;
    if (cond) goto L003E6250;
    v0 = func_003FF330(a0, a1, a2, a3, t0, t1, t2);
    f0 = *(float*)((char*)s3 + 44);
    cond = s2 == 0;
    *(float*)((char*)s1 + 12) = f0;
    if (cond) goto L003E6250;
    s0 = 0 + 16;
    v0 = *(int*)(char*)D_0055A1E0;
    *(int*)(char*)s2 = v0;
L003E6250:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
