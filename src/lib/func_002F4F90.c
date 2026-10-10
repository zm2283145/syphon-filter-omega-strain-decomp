#include "types.h"

extern int func_002DA900(int, int);

int func_002F4F90(int a0, int a1) {
    *(int*)((char*)a1) = (0 | 65535);
    return func_002DA900(a0, a1);
}
