#include "types.h"
typedef void (*Hook_00322468)(void);
extern unsigned short D_004E1D4C;
extern Hook_00322468 D_004E1D38;
extern void func_001253C0(void);
int func_00322468(Hook_00322468 fn)
{
    if (D_004E1D4C) return 0x184C;
    if (!fn) fn = (Hook_00322468)func_001253C0;
    D_004E1D38 = fn;
    return 0;
}