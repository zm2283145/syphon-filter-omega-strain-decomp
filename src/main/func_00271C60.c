#include "types.h"

extern void func_003E8DE0(int, int);

void func_00271C60(int a0) {
    int a1, s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 40);
    cond = a0 == 0;
    if (cond) goto L00271C88;
    func_003E8DE0(a0, a1);
L00271C88:;
    a0 = *(int*)((char*)s0 + 36);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CA0;
    func_003E8DE0(a0, a1);
L00271CA0:;
    a0 = *(int*)((char*)s0 + 56);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CB8;
    func_003E8DE0(a0, a1);
L00271CB8:;
    goto ret;
ret:;
}
