#include "types.h"

extern int Awards_FindRequirementRow(int, int, int);

void func_00333860(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = Awards_FindRequirementRow(a0, a1, a2);
    cond = v0 == 0;
    v1 = 0 + 2;
    if (cond) goto L00333880;
    *(char*)(char*)v0 = v1;
L00333880:;
    goto ret;
ret:;
}
