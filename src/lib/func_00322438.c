#include "types.h"
typedef void (*Hook_00322438)(void);
extern unsigned short D_004E1D4C;
extern Hook_00322438 D_004E1D34;
extern void func_00121D00(void);
int func_00322438(Hook_00322438 fn)
{
    if (D_004E1D4C) return 0x184C;
    if (!fn) fn = (Hook_00322438)func_00121D00;
    D_004E1D34 = fn;
    return 0;
}