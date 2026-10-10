#include "types.h"

extern char D_004D9280[];
extern int func_003EC950(int);

int func_001449B0(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    cond = s0 == 0;
    if (cond) goto L001449E8;
    v1 = (int)D_004D9280;
    v0 = (short)a1;
    cond = v0 <= 0;
    *(int*)((char*)s0 + 4) = v1;
    if (cond) goto L001449E8;
    v0 = func_003EC950(a0);
L001449E8:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
