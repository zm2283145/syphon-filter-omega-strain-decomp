#include "types.h"

void func_0024FC90(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L0024FCA8;
    v1 = a1 + 12;
    goto L0024FCB8;
L0024FCA8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L0024FCB8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
