#include "types.h"

void func_001AF300(int a0, float f12) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF310;
    *(float*)(char*)a0 = f12;
L001AF310:;
    goto ret;
ret:;
}
