#include "types.h"
typedef void (*Hook_003224D8)(void);
extern unsigned short D_004E1D4C;
extern Hook_003224D8 D_004E1D44;
extern void Math_Cos(void);
int func_003224D8(Hook_003224D8 fn)
{
    if (!fn) fn = (Hook_003224D8)Math_Cos;
    D_004E1D44 = fn;
    return 0;
}