#include "types.h"

extern char D_0058805C[];
extern int Newlib_SysFstat(int, int);

int Newlib_FstatR(int a0, int a1, int a2) {
    int s0, s1, v0, v1;

    s0 = a0;
    s1 = (int)D_0058805C;
    a0 = a1;
    a1 = a2;
    *(int*)(char*)s1 = 0;
    v0 = Newlib_SysFstat(a0, a1);
    v1 = v0;
    a0 = 0 + -1;
    if (v1 != a0) {
    goto L001246C4;
    }
    v1 = *(int*)(char*)s1;
    if (v1 != 0) {
    *(int*)(char*)s0 = v1;
    goto L001246C0;
    }
L001246C0:;
L001246C4:;
    goto ret;
ret:
    return v0;
}
