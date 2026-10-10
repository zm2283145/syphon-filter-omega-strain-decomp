#include "types.h"

extern int func_0023EB70(int);

int func_002244D0(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = 0 + 1;
    a1 = *(unsigned char*)((char*)a0 + 73);
    cond = a1 != v1;
    v0 = 0;
    if (cond) goto L002244F0;
    v0 = a0;
    goto L00224520;
L002244F0:;
    v1 = 0 + 15;
    cond = a1 != v1;
    if (cond) goto L00224508;
    v0 = *(int*)((char*)a0 + 100);
    goto L00224520;
L00224508:;
    v1 = 0 + 16;
    cond = a1 != v1;
    if (cond) goto L00224520;
    v0 = func_0023EB70(a0);
L00224520:;
    goto ret;
ret:
    return v0;
}
