#include "types.h"
#pragma bool off
static inline int E1IsNone(int x) { return x == -1; }
typedef struct { char pad[0x18]; int id; char pad1c[0x84 - 0x1C]; unsigned char state; unsigned char sub; char pad86[2]; char* equip; char pad8c[0xA4 - 0x8C]; int timer; } AnimHost_e1;
extern unsigned char D_00489D78[];
extern unsigned char D_00489D70[];
extern void Equip_SwapSlots(void*, int, int);
void func_00142BB0(AnimHost_e1* self, unsigned char b)
{
    if (b == 0 && (E1IsNone(self->id) ^ 1)) {
        func_00142BB0(self, 1);
    }
    Equip_SwapSlots(self->equip + 0x60, D_00489D78[b], D_00489D70[b]);
    self->state = 6;
    self->sub = b;
    self->timer = -1;
}