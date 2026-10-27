#include "types.h"

extern void MEMCPY16(int, int, int);
extern int cString16N_3_Empty(int);

int cString16N_3_opAssign(int a0, int a1) {
    int a2, s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    v0 = cString16N_3_Empty(a0);
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00209548;
    v0 = cString16N_3_Empty(a0);
    cond = v0 != 0;
    if (cond) goto L00209558;
L00209548:;
    a1 = s0;
    a0 = s1;
    a2 = 0 + 3;
    MEMCPY16(a0, a1, a2);
L00209558:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
