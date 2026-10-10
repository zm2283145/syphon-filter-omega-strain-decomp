#include "types.h"

extern char D_0048C448[];

void func_002DCA38(void) {
    int tmp0;

    tmp0 = *(int*)(char*)(int)D_0048C448;
    *(int*)((char*)(int)D_0048C448) = (tmp0 + 1);
}
