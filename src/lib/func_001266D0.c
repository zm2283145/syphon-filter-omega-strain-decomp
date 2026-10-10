#include "types.h"

extern int func_00126280(int, int);

int func_001266D0(int a0, int a1) {
    int tmp0;

    tmp0 = func_00126280(a0, 1);
    *(int*)((char*)tmp0 + 20) = a1;
    *(int*)((char*)tmp0 + 16) = 1;
    return tmp0;
}
