#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

extern void func_0010D590(int command, int* params);

/* SDK: issues command -6 with parameters {a, b, (unsigned short)c}. */
void func_0010E408(int a, int b, unsigned short c)
{
    int params[3];
    params[0] = a;
    params[1] = b;
    params[2] = c;
    func_0010D590(-6, params);
}
