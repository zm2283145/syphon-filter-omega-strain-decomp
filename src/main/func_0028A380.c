#include "types.h"

void func_0028A380(int a0, int a1) {
    int a2, v1;
    int cond;

    a2 = *(int*)((char*)a0 + 136);
    cond = a2 == 0;
    if (cond) goto L0028A3B8;
    cond = a1 == 0;
    if (cond) goto L0028A3A8;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a2 + 20) = v1;
    goto L0028A3B8;
L0028A3A8:;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a2 + 20) = v1;
L0028A3B8:;
    a2 = *(int*)((char*)a0 + 144);
    cond = a2 == 0;
    if (cond) goto L0028A3F0;
    cond = a1 == 0;
    if (cond) goto L0028A3E0;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a2 + 20) = v1;
    goto L0028A3F0;
L0028A3E0:;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a2 + 20) = v1;
L0028A3F0:;
    a0 = *(int*)((char*)a0 + 152);
    cond = a0 == 0;
    if (cond) goto L0028A428;
    cond = a1 == 0;
    if (cond) goto L0028A418;
    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a0 + 20) = v1;
    goto L0028A428;
L0028A418:;
    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a0 + 20) = v1;
L0028A428:;
    goto ret;
ret:;
}
