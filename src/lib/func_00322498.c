#include "types.h"
typedef void (*Hook_00322498)(void);
extern unsigned short D_004E1D4C;
extern Hook_00322498 D_004E1D3C;
extern void memset(void);
int func_00322498(Hook_00322498 fn)
{
    if (!fn) fn = (Hook_00322498)memset;
    D_004E1D3C = fn;
    return 0;
}