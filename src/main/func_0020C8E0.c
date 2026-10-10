#include "types.h"
#pragma optimization_level 1

extern void func_001F2800(int, int);

/* Calls func_001F2800(b, -1). */
void func_0020C8E0(int a, int b) {
    func_001F2800(b, -1);
}
