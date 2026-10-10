#include "types.h"

extern char D_005141C0[];

int func_002BA9E8(void) {
    int a0, v0, v1;
    int cond;

    a0 = 0 + -1;
    v0 = (int)D_005141C0;
    v1 = 0 + 1;
L002BA9F8:;
    v1 = v1 + -1;
    *(int*)(char*)v0 = a0;
    *(int*)((char*)v0 + 12) = 0;
    cond = v1 >= 0;
    v0 = v0 + 8208;
    if (cond) goto L002BA9F8;
    v0 = 0 + 1;
    goto ret;
ret:
    return v0;
}
