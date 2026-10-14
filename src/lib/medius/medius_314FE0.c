#include "types.h"

extern int func_002E6098(int);

int func_00314FE0(int a0) {
    int s0, v0;
    int cond;

    cond = a0 == 0;
    if (cond) goto L00315010;
    s0 = *(unsigned char*)((char*)a0 + 8);
    v0 = 0 + 1;
    if (s0 != v0) {
    v0 = 0;
    goto L00315014;
    }
    a0 = *(int*)(char*)a0;
    v0 = func_002E6098(a0);
    cond = v0 == s0;
    if (cond) goto L00315018;
L00315010:;
    v0 = 0;
L00315014:;
L00315018:;
    goto ret;
ret:
    return v0;
}
