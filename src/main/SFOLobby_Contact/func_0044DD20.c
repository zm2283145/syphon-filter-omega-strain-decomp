#include "types.h"
typedef struct {
    char p0[0x23E8]; void* f23E8; void* f23EC;
    char p23F0[0x255C - 0x23F0]; int state;
} S44DD20;
extern void func_00452FC0(S44DD20*, int);
extern void func_0044F6B0(void*);
void func_0044DD20(S44DD20* s)
{
    int st = s->state;
    if (st == 9) return;
    if (st == 6 || st == 10) {
        if (st != 10) s->state = 9;
        func_00452FC0(s, 0);
        if (s->f23EC) func_0044F6B0(s->f23EC);
        s->f23EC = 0;
        if (s->f23E8) func_0044F6B0(s->f23E8);
        s->f23E8 = 0;
    }
}
