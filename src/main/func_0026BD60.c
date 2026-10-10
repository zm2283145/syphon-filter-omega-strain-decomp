#include "types.h"

extern char D_004FEED0[];
extern char D_0055A340[];
extern char D_0055A500[];
extern int func_00369920(int, int, int);

int func_0026BD60(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    a0 = 0;
    v1 = (int)D_004FEED0;
L0026BD78:;
    *(char*)((char*)v1 + 24) = 0;
    *(char*)((char*)v1 + 52) = 0;
    a0 = a0 + 1;
    *(char*)((char*)v1 + 80) = 0;
    v0 = a0 < 2;
    *(char*)((char*)v1 + 108) = 0;
    *(char*)((char*)v1 + 136) = 0;
    *(char*)((char*)v1 + 164) = 0;
    cond = v0 != 0;
    v1 = v1 + 168;
    if (cond) goto L0026BD78;
    a1 = 0;
    a0 = (int)D_0055A340;
    a2 = 0;
    v0 = func_00369920(a0, a1, a2);
    a1 = 0;
    a0 = (int)D_0055A500;
    a2 = 0;
    v0 = func_00369920(a0, a1, a2);
    goto ret;
ret:
    return v0;
}
