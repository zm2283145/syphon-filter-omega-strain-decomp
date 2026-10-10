#include "types.h"

extern int func_00142C50(int, int);
extern void func_00143B60(int);

void func_001B8790(int a0, int a1, int a2) {
    int v0;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    cond = a0 == 0;
    if (cond) goto L001B87C8;
    cond = a1 == 0;
    if (cond) goto L001B87C0;
    func_00143B60(a0);
    goto L001B87C8;
L001B87C0:;
    a1 = a2;
    v0 = func_00142C50(a0, a1);
L001B87C8:;
    goto ret;
ret:;
}
