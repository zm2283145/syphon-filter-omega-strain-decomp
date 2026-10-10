#include "types.h"

extern void func_003A7F80(int);
extern void func_003A7FB0(int);

void func_001C96D0(int a0, int a1) {
    int cond;

    cond = a1 == 0;
    if (cond) goto L001C96F0;
    a0 = 0 + -1;
    func_003A7FB0(a0);
    goto L001C96F8;
L001C96F0:;
    a0 = 0 + -1;
    func_003A7F80(a0);
L001C96F8:;
    goto ret;
ret:;
}
