#include "types.h"

extern void func_003E8DE0(int, int);

void func_002449A0(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L002449C0;
    func_003E8DE0(a0, a1);
L002449C0:;
    goto ret;
ret:;
}
