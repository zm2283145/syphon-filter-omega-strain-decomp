/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001396D0(int, int);
extern int func_00173970(int);

int func_00173900(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_00173910(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00173930(int a0) {
    *(int*)((char*)a0) = 0;
    func_00173970(a0);
    *(int*)((char*)a0 + 8) = (a0 + 4);
    *(int*)((char*)a0 + 4) = (a0 + 4);
    return a0;
}
