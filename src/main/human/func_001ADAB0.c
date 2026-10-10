#include "types.h"

void func_001ADAB0(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L001ADAC8;
    v1 = a1 + 12;
    goto L001ADAD8;
L001ADAC8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001ADAD8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
