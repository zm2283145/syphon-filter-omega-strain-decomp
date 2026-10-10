#include "types.h"

extern int func_002EBC48(int);

int func_002D0620(int a0) {
    int s0, v0;

    s0 = a0;
    v0 = func_002EBC48(a0);
    if (v0 == 0) {
    goto L002D0648;
    }
    *(int*)(char*)s0 = 0;
    v0 = 0 + -17;
L002D0648:;
    goto ret;
ret:
    return v0;
}
