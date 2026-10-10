#include "types.h"

int func_0015AD10(int a0) {
    int a1, v0, v1;
    int cond;

    a1 = 0;
    v1 = a0;
L0015AD18:;
    *(int*)((char*)v1 + 92) = 0;
    *(int*)((char*)v1 + 96) = 0;
    a1 = a1 + 3;
    *(int*)((char*)v1 + 100) = 0;
    v0 = a1 < 9;
    cond = v0 != 0;
    v1 = v1 + 12;
    if (cond) goto L0015AD18;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
