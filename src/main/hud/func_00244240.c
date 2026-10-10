#include "types.h"

extern void func_00244280(int);
extern void func_003E9730(int);

void func_00244240(int a0) {
    int s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 100);
    cond = a0 == 0;
    if (cond) goto L00244268;
    func_003E9730(a0);
L00244268:;
    a0 = s0;
    func_00244280(a0);
    goto ret;
ret:;
}
