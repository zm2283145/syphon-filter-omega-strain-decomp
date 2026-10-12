#include "types.h"
typedef struct { char p[0x255C]; int state; } S4426B0;
extern void func_00452FC0(S4426B0* s, int f);
void func_004426B0(S4426B0* s)
{
    int st = s->state;
    if (st != 9 && (st == 4 || st == 0)) {
        s->state = 9;
        func_00452FC0(s, 0);
    }
}
