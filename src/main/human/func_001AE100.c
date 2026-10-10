#include "types.h"

void func_001AE100(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 11632) = a1;
    if (cond) goto L001AE118;
    v1 = a1 + 12;
    goto L001AE128;
L001AE118:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001AE128:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 11636) = v1;
    *(int*)((char*)a0 + 11660) = 0;
    goto ret;
ret:;
}
