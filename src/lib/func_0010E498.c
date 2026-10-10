#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

extern void func_0010D590(int command, int* params);

/* SDK: issues command -9 with a single parameter. */
void func_0010E498(int a)
{
    int params[1];
    params[0] = a;
    func_0010D590(-9, params);
}
