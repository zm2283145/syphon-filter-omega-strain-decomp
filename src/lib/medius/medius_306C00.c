#include "types.h"

extern char D_00491308[];
extern char D_00529830[];
extern int func_00306BF0(void);

int func_00306C00(void) {
    int s0, s1, v0, v1;
    int cond;

    s1 = (int)D_00491308;
    v1 = *(unsigned char*)(char*)s1;
    cond = v1 != 0;
    if (cond) goto L00306C44;
    s0 = (int)D_00529830;
    *(int*)(char*)s0 = 0;
    *(int*)((char*)s0 + 4) = 0;
    *(int*)((char*)s0 + 8) = 0;
    v0 = func_00306BF0();
    v1 = 0 + 1;
    *(int*)((char*)s0 + 12) = v0;
    *(char*)(char*)s1 = v1;
L00306C44:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
