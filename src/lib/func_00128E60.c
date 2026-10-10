#include "types.h"

extern int func_00121E20(int, int);

int func_00128E60(int a0) {
    short tmp0;
    int tmp1;

    tmp0 = *(short*)((char*)a0 + 14);
    tmp1 = *(int*)((char*)a0 + 84);
    return func_00121E20(tmp1, tmp0);
}
