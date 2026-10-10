#include "types.h"

extern char D_00539248[];
extern int func_00382C30(int, int);

void func_003BB010(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    cond = a1 != 0;
    s0 = a0;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)D_00539248;
    a1 = *(int*)(char*)s0;
    v0 = func_00382C30(a0, a1);
    a1 = *(int*)((char*)s0 + 4);
    v1 = 0 + -1;
    cond = a1 == v1;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)D_00539248;
    v0 = func_00382C30(a0, a1);
L003BB050:;
    goto ret;
ret:;
}
