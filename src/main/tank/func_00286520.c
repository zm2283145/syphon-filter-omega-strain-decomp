#include "types.h"

void func_00286520(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 92) = a1;
    if (cond) goto L00286538;
    v1 = a1 + 12;
    goto L00286548;
L00286538:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00286548:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 96) = v1;
    goto ret;
ret:;
}
