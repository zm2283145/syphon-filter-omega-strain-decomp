#include "types.h"

extern char D_0055A1F0[];
extern int func_003FF330(int, int, int, int, int, int, int);

int func_003E6170(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int s0, s1, s2, s3, v0;
    int cond;

    v0 = (unsigned int)t1 < (unsigned int)16;
    s3 = a0;
    s2 = a2;
    s1 = t2;
    cond = v0 != 0;
    s0 = 0 + -1;
    if (cond) goto L003E61D0;
    cond = s1 == 0;
    a2 = 0;
    if (cond) goto L003E61D0;
    v0 = func_003FF330(a0, a1, a2, a3, t0, t1, t2);
    v0 = *(int*)((char*)s3 + 44);
    cond = s2 == 0;
    *(int*)((char*)s1 + 12) = v0;
    if (cond) goto L003E61D0;
    s0 = 0 + 16;
    v0 = *(int*)(char*)D_0055A1F0;
    *(int*)(char*)s2 = v0;
L003E61D0:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
