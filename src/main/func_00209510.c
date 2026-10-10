#include "types.h"

extern void func_001AE170(int, int, int);
extern int func_001AE190(int);

int func_00209510(int a0, int a1) {
    int a2, s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    v0 = func_001AE190(a0);
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00209548;
    v0 = func_001AE190(a0);
    cond = v0 != 0;
    if (cond) goto L00209558;
L00209548:;
    a1 = s0;
    a0 = s1;
    a2 = 0 + 3;
    func_001AE170(a0, a1, a2);
L00209558:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
