#include "types.h"

extern int func_002324A0(int, int);
extern int func_003EBFB0(int);

void Effect_CreateInstance(int a0, int a1) {
    int loc[2];
    int v0;
    int cond;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 24;
    v0 = func_003EBFB0(a0);
    a0 = v0;
    cond = a0 == 0;
    a1 = (int)loc;
    if (cond) goto L00232490;
    v0 = func_002324A0(a0, a1);
L00232490:;
    goto ret;
ret:;
}
