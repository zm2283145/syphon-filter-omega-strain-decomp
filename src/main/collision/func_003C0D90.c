#include "types.h"

void func_003C0D90(int a0, int a1, int a2, int a3) {
    int v1;
    int cond;

    v1 = *(int*)((char*)a0 + 4);
    cond = v1 != 0;
    if (cond) goto L003C0DB8;
    *(int*)(char*)a1 = 0;
    v1 = 0 + 1;
    *(int*)(char*)a2 = v1;
    v1 = 0 + 2;
    *(int*)(char*)a3 = v1;
    goto L003C0DE8;
L003C0DB8:;
    a0 = 0 + 1;
    cond = v1 != a0;
    if (cond) goto L003C0DD8;
    *(int*)(char*)a1 = a0;
    v1 = 0 + 2;
    *(int*)(char*)a2 = v1;
    *(int*)(char*)a3 = 0;
    goto L003C0DE8;
L003C0DD8:;
    v1 = 0 + 2;
    *(int*)(char*)a1 = v1;
    *(int*)(char*)a2 = 0;
    *(int*)(char*)a3 = a0;
L003C0DE8:;
    goto ret;
ret:;
}
