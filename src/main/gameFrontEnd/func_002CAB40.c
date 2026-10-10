#include "types.h"

extern void func_002A7DD0(int, int);

void func_002CAB40(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 600);
    cond = a0 == 0;
    if (cond) goto L002CAB60;
    func_002A7DD0(a0, a1);
L002CAB60:;
    goto ret;
ret:;
}
