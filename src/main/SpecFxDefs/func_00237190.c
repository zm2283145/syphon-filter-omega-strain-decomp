#include "types.h"

extern char D_004DBB00[];
extern int func_003EBF10(int);
extern int func_003EC050(int, int);

int func_00237190(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L002371D8;
    a1 = 0;
    v0 = (int)D_004DBB00;
    *(int*)((char*)s1 + 20) = v0;
    v0 = func_003EC050(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L002371D8;
    v0 = func_003EBF10(a0);
L002371D8:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
