#include "types.h"

int Agent_GetSelected(int a0, int a1) {
    int v0;
    int cond;

    v0 = 0 + -1;
    cond = a1 != v0;
    if (cond) goto L00131500;
    a1 = *(int*)((char*)a0 + 472);
L00131500:;
    v0 = a1 << 2;
    v0 = v0 + a0;
    v0 = *(int*)((char*)v0 + 456);
    goto ret;
ret:
    return v0;
}
