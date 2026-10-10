#include "types.h"

extern char D_004FFC2C[];
extern void func_0045BEB0(int, int);

void func_00176160(void) {
    int a0, a1, v1;
    int cond;

    v1 = *(int*)(char*)D_004FFC2C;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    if (cond) goto L00176188;
    func_0045BEB0(a0, a1);
L00176188:;
    goto ret;
ret:;
}
