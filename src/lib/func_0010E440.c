#include "types.h"

extern void func_0010D590(int command, int* params);

/* SDK (EE-GCC): issues command -7 with parameters {a, (signed char)b}. */
void func_0010E440(int a, signed char b) {
    int params[2];
    params[0] = a;
    params[1] = b;
    func_0010D590(-7, params);
}
