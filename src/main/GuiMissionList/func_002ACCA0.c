#include "types.h"

extern int func_002ACB70(int);
extern int func_0041E3B0(int, float);

void func_002ACCA0(int a0) {
    int s0, v0, v1;
    float f12;
    int cond;

    s0 = a0;
    v0 = func_0041E3B0(a0, f12);
    v1 = *(int*)((char*)s0 + 284);
    cond = v1 == 0;
    if (cond) goto L002ACCD8;
    v1 = *(unsigned char*)((char*)v1 + 24);
    cond = v1 == 0;
    a0 = s0;
    if (cond) goto L002ACCD8;
    v0 = func_002ACB70(a0);
L002ACCD8:;
    goto ret;
ret:;
}
