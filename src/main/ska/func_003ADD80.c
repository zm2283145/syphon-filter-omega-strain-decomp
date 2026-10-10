#include "types.h"

void AnimTime_Pop(int a0) {
    int v1;
    int cond;

    v1 = *(int*)(char*)a0;
    cond = v1 == 0;
    if (cond) goto L003ADD98;
    v1 = v1 + -1;
    *(int*)(char*)a0 = v1;
L003ADD98:;
    goto ret;
ret:;
}
