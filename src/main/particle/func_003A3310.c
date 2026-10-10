#include "types.h"

void func_003A3310(int a0, float f12, float f13) {
    int v1;
    int cond;

    a0 = *(int*)((char*)a0 + 8);
    v1 = *(int*)((char*)a0 + 116);
    cond = v1 == 0;
    if (cond) goto L003A3328;
    a0 = v1;
L003A3328:;
    *(float*)((char*)a0 + 288) = f12;
    *(float*)((char*)a0 + 292) = f13;
    goto ret;
ret:;
}
