#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define AND &&
struct Act_DFB0 { char pad[0xC]; int serial; };
struct Mode_DFB0 { int prio; unsigned char active; unsigned char b; char pad[0xE]; };
struct Npc_DFB0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x7C]; int x80; char pad84[0xE0]; unsigned char mode; char pad165[7]; Act_DFB0* target; int serial; float f; Mode_DFB0 modes[1]; };
struct Rec_DFB0 { Act_DFB0* target; int serial; float f; int prio; unsigned char a; unsigned char b; };
#pragma push



#define R(s) ((Rec_DFB0*)((char*)(s) + 0x16C))
extern "C" void cNPC_v48(Npc_DFB0* self, Act_DFB0* a, int prio, float f)
{
    if (prio >= self->modes[0].prio) {
        if (prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DFB0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DFB0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 0;
        self->target = a;
        { int none; self->serial = *(a ? &a->serial : (none = -1, &none)); }
        self->modes[0].active = 1;
        self->modes[0].b = 1;
        self->f = f;
        self->modes[0].prio = prio;
        }
        self->x80 = 0;
    }
}
#pragma pop
