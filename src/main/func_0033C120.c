/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00532A70[];
extern void func_00100440(int, int, int, int);
extern int func_0033C280(int);
extern int func_0033C2A0(int, int);

Rel* func_0033C120(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void func_0033C140(void) {
    func_00100440((int)D_00532A70, (int)func_0033C2A0, 16, 5);
}

int func_0033C160(int a0) {
    func_0033C280(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
