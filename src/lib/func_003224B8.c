#include "types.h"
typedef void (*Hook_003224B8)(void);
extern unsigned short D_004E1D4C;
extern Hook_003224B8 D_004E1D40;
extern void memcpy(void);
int func_003224B8(Hook_003224B8 fn)
{
    if (!fn) fn = (Hook_003224B8)memcpy;
    D_004E1D40 = fn;
    return 0;
}