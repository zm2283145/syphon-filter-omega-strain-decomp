#include "types.h"

extern char D_00489738[];
extern int func_00124E98(int, int, int);

int func_00124F38(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_00124E98(tmp0, a0, a1);
}
