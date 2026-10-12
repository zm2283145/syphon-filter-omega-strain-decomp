#include "types.h"
extern int D_0048C458;
extern int D_0058C138[];
extern int D_0058C0B8[];
extern int D_0058C0F8[];
int func_002ED570(unsigned int i, int b, int c, int d)
{
    if (!D_0048C458) return 0x11;
    if (i >= 16) return 0x17;
    D_0058C0B8[i] = b;
    D_0058C0F8[i] = c;
    D_0058C138[i] = d;
    return 0;
}
