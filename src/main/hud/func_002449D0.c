#include "types.h"

extern void func_003E8DE0(int, int);

void func_002449D0(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0 + 1;
    if (cond) goto L002449F0;
    func_003E8DE0(a0, a1);
L002449F0:;
    goto ret;
ret:;
}
