#include "types.h"

extern int func_002EF230(int);

int func_002EF200(int a0) {
    int s0, v0, v1;

    s0 = a0;
    v0 = func_002EF230(a0);
    v1 = *(int*)((char*)s0 + 104);
    v0 = 0 + -1;
    if (v1 != 0) v0 = 0;
    goto ret;
ret:
    return v0;
}
