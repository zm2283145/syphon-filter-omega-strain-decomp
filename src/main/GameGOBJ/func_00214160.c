#include "types.h"

extern int func_002141A0(int);
extern int func_00214240(int);

int func_00214160(int a0) {
    int s0, v0;
    int cond;

    s0 = a0;
    v0 = func_00214240(a0);
    v0 = v0 & 255;
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00214190;
    v0 = func_002141A0(a0);
    v0 = v0 & 255;
L00214190:;
    goto ret;
ret:
    return v0;
}
