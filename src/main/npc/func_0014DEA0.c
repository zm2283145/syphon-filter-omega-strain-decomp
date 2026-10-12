#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define AND &&
struct Act_DEA0 { char pad[0xC]; int serial; };
struct Mode_DEA0 { int prio; unsigned char active; char pad[0xF]; };
struct Npc_DEA0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x160]; unsigned char mode; char pad165[0x13]; Mode_DEA0 modes[1]; char pad18c[0x8]; Act_DEA0* target; int targetSerial; float x19C; int prio; unsigned char x1A4; unsigned char x1A5; };
#pragma push



extern "C" void cNPC_v49(Npc_DEA0* self, Act_DEA0* a, int prio, float f)
{
    if (prio >= self->prio AND prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DEA0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DEA0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 2;
        self->target = a;
        { int none; self->targetSerial = *(a ? &a->serial : (none = -1, &none)); }
        self->x1A4 = 1;
        self->x1A5 = 1;
        self->x19C = f;
        self->prio = prio;
    }
}
#pragma pop
