#include "types.h"

extern char D_00489738[];
extern int func_0012AC90(int, int, int);

int func_0012AC70(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_0012AC90(a0, a1, (tmp0 + 92));
}
