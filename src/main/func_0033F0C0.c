#include "types.h"

extern int func_002ACC80(int, int);
extern int func_004147A0(void);

int func_0033F0C0(int a0) {
    int a1, v0, v1;
    int cond;

    v0 = *(unsigned char*)((char*)a0 + 128);
    cond = v0 == 0;
    if (cond) goto L0033F0F0;
    *(int*)((char*)a0 + 168) = 0;
    a0 = *(int*)((char*)a0 + 136);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L0033F0F0;
    v0 = func_002ACC80(a0, a1);
L0033F0F0:;
    v0 = func_004147A0();
    v1 = *(int*)((char*)v0 + 104);
    v1 = v1 | 12;
    *(int*)((char*)v0 + 104) = v1;
    goto ret;
ret:
    return v0;
}
