#include "types.h"

int func_002F7F10(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    if (cond) goto L002F7F54;
    cond = a1 == 0;
    if (cond) goto L002F7F54;
    v1 = *(int*)((char*)a1 + 4);
    cond = v1 == 0;
    v0 = *(int*)(char*)a1;
    if (cond) goto L002F7F38;
    *(int*)(char*)v1 = v0;
    goto L002F7F3C;
L002F7F38:;
    *(int*)((char*)a0 + 12) = v0;
L002F7F3C:;
    v1 = *(int*)(char*)a1;
    cond = v1 == 0;
    v0 = *(int*)((char*)a1 + 4);
    if (cond) goto L002F7F50;
    *(int*)((char*)v1 + 4) = v0;
    goto ret;
L002F7F50:;
    *(int*)((char*)a0 + 8) = v0;
L002F7F54:;
    goto ret;
ret:
    return v0;
}
