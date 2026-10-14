#include "types.h"

extern int func_002F7D68(int);

void func_002F84A0(int a0, int a1) {
    int s0, v0;

    s0 = a1;
    v0 = func_002F7D68(a0);
    if (v0 != 0) {
    *(int*)((char*)v0 + 20) = s0;
    goto L002F84BC;
    }
L002F84BC:;
    goto ret;
ret:;
}
