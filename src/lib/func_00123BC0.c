#include "types.h"

extern char D_00489738[];
extern int func_00123AE0(int, int, int);

int func_00123BC0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_00123AE0(tmp0, a0, a1);
}
