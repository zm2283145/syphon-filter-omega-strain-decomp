#include "types.h"

extern int func_00138DA0(int, int, int);

int func_001642E0(int a0) {
    int loc[2];
    int a1, a2, s0, v0;
    int cond;

    v0 = *(int*)((char*)a0 + 44);
    cond = v0 <= 0;
    s0 = 0;
    if (cond) goto L00164318;
    v0 = *(int*)((char*)a0 + 52);
    a1 = a0 + 44;
    a2 = (int)loc;
    s0 = *(int*)((char*)v0 + 8);
    a0 = (int)((char*)loc + 4);
    *(int*)(char*)loc = v0;
    v0 = func_00138DA0(a0, a1, a2);
L00164318:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
