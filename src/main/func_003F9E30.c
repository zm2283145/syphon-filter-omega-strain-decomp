#include "types.h"

extern void func_003E8DE0(int, int);

void func_003F9E30(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 1288);
    cond = a0 == 0;
    if (cond) goto L003F9E50;
    func_003E8DE0(a0, a1);
L003F9E50:;
    goto ret;
ret:;
}
