#include "types.h"

void func_001AF3E0(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF3F0;
    *(int*)(char*)a0 = 0;
L001AF3F0:;
    goto ret;
ret:;
}
