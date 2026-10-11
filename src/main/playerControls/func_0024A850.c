#include "types.h"
#include "prio_bitset.h"
PB_DEFINE(PS_24A850, 1)
typedef struct { char pad[0x30]; int x30; int x34; int x38; int x3C; PS_24A850 ps; } O_24A850;
typedef struct { char pad[0x2E00]; unsigned char state; } X_24A850;
extern int func_0017A610(void* y);
extern void func_00249460(O_24A850* o, X_24A850* x);
extern unsigned char D_005721C8;
#pragma opt_rotateloops off
void func_0024A850(O_24A850* o, X_24A850* x, void* y, float val)
{
    int i;
    if (o->x38 == 8 && !func_0017A610(y)) x->state = 2;
    if (val &&  !((o->x3C >> 11) & 1)) {
        PS_24A850_Set(&o->ps, 8);
        PB_FIND_TOP(PS_24A850, (&o->ps), i, 12)
    } else {
        PS_24A850_Clr(&o->ps, 8);
        PB_FIND_TOP(PS_24A850, (&o->ps), i, 12)
    }
    {
        int c = o->x30 == 8 && !(o->x38 == 8);
        if (c) {
            x->state = 0;
            if (D_005721C8) func_00249460(o, x);
        }
    }
}
#pragma opt_rotateloops reset