#include "types.h"

int func_003FCD80(int a0) {
    int a1, v0, v1;
    int cond;

    *(char*)((char*)a0 + 20) = 0;
    a1 = 0;
    *(int*)((char*)a0 + 24) = 0;
    v1 = a0;
    *(short*)((char*)a0 + 148) = 0;
L003FCD98:;
    *(int*)((char*)v1 + 28) = 0;
    *(int*)((char*)v1 + 32) = 0;
    a1 = a1 + 6;
    *(int*)((char*)v1 + 36) = 0;
    v0 = a1 < 30;
    *(int*)((char*)v1 + 40) = 0;
    *(int*)((char*)v1 + 44) = 0;
    *(int*)((char*)v1 + 48) = 0;
    cond = v0 != 0;
    v1 = v1 + 24;
    if (cond) goto L003FCD98;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
