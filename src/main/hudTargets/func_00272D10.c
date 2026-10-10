#include "types.h"

void func_00272D10(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 52) = a1;
    if (cond) goto L00272D28;
    v1 = a1 + 12;
    goto L00272D38;
L00272D28:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00272D38:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 56) = v1;
    goto ret;
ret:;
}
