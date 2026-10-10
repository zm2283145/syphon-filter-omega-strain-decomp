#include "types.h"

extern char D_004DFD80[];
extern char D_005721C8[];
extern char D_005721D0[];
extern int func_0042B1A0(int);

int Event_Construct(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    v1 = (int)D_004DFD80;
    v0 = 0 + 5;
    *(int*)(char*)a0 = v1;
    *(int*)((char*)a0 + 4) = a1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0 + 28) = 0;
    *(char*)((char*)a0 + 32) = v0;
    v0 = *(unsigned char*)(char*)D_005721C8;
    cond = v0 == 0;
    s0 = a0;
    if (cond) goto L003C9E88;
    v0 = *(unsigned char*)(char*)D_005721D0;
    cond = v0 == 0;
    a0 = 0;
    if (cond) goto L003C9E88;
    v0 = func_0042B1A0(a0);
    *(int*)((char*)s0 + 12) = v0;
L003C9E88:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
