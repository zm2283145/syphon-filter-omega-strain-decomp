#include "types.h"

void SkelNode_ClearWeight(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF3F0;
    *(int*)(char*)a0 = 0;
L001AF3F0:;
    goto ret;
ret:;
}
