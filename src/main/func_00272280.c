#include "types.h"

extern void func_003E8EB0(int);

void func_00272280(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L00272298;
    func_003E8EB0(a0);
L00272298:;
    goto ret;
ret:;
}
