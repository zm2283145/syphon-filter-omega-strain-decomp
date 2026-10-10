#include "types.h"

extern char D_004FFC2C[];
extern int func_003CB1C0(int);
extern void func_0045BEB0(int, int);

int Script_cPlayer_SetMenuReceiver(int a0) {
    int a1, v0, v1;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    v0 = func_003CB1C0(a0);
    v1 = *(int*)(char*)D_004FFC2C;
    a0 = *(int*)((char*)v1 + 1700);
    cond = a0 == 0;
    a1 = v0;
    if (cond) goto L00175D90;
    func_0045BEB0(a0, a1);
L00175D90:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
