#include "types.h"
typedef void (*Hook_003224F8)(void);
extern unsigned short D_004E1D4C;
extern Hook_003224F8 D_004E1D48;
extern void Math_Sin(void);
int func_003224F8(Hook_003224F8 fn)
{
    if (!fn) fn = (Hook_003224F8)Math_Sin;
    D_004E1D48 = fn;
    return 0;
}