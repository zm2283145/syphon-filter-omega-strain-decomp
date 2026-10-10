#include "types.h"

extern int func_002ED8D8(int);

int func_002D9E30(int a0, int a1) {
    int s0, v0;
    int cond;

    s0 = a1;
    cond = s0 == 0;
    if (cond) goto L002D9E60;
    v0 = *(int*)((char*)a0 + 100);
    cond = s0 != v0;
    if (cond) goto L002D9E58;
    *(int*)((char*)a0 + 100) = 0;
    goto L002D9E60;
L002D9E58:;
    a0 = s0;
    v0 = func_002ED8D8(a0);
L002D9E60:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
