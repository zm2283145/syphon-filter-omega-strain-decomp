#include "types.h"

int func_00176EF0(int a0, int a1) {
    int loc[1];
    int v0, v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L00176F08;
    v0 = a1 + 12;
    goto L00176F18;
L00176F08:;
    v0 = 0 + -1;
    *(int*)(char*)loc = v0;
    v0 = (int)loc;
L00176F18:;
    v1 = *(int*)(char*)v0;
    v0 = a1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:
    return v0;
}
