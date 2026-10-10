#include "types.h"

extern int func_00369050(int, int, int);

int func_003696B0(int a0, int a1, int a2) {
    int v0;
    int cond;

    v0 = *(int*)(char*)a0;
    cond = v0 < 0;
    if (cond) goto L003696D0;
    *(int*)((char*)a0 + 40) = a2;
    goto L003696E0;
L003696D0:;
    v0 = func_00369050(a0, a1, a2);
    goto L003696E8;
L003696E0:;
    v0 = 0 + 1;
L003696E8:;
    goto ret;
ret:
    return v0;
}
