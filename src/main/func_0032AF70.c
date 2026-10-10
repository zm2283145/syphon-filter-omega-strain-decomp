#include "types.h"

extern int func_0032B260(int, int);

int func_0032AF70(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    a1 = 0 + 1002;
    v0 = func_0032B260(a0, a1);
    cond = s0 == v0;
    a0 = s1;
    if (cond) goto L0032AFC0;
    a1 = 0 + 1032;
    v0 = func_0032B260(a0, a1);
    cond = s0 == v0;
    a0 = s1;
    if (cond) goto L0032AFC0;
    a1 = 0 + 57;
    v0 = func_0032B260(a0, a1);
    cond = s0 == v0;
    if (cond) goto L0032AFC0;
    v0 = 0;
    goto L0032AFC8;
L0032AFC0:;
    v0 = 0 + 1;
L0032AFC8:;
    goto ret;
ret:
    return v0;
}
