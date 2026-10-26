#pragma cplusplus on
#include "types.h"
struct Bits2CA0 { unsigned char f0 : 1; };
struct Npc2CA0 { char pad[0x214]; Bits2CA0 bits; };
struct Ev2CA0 { void* vtable; char pad[0x20]; unsigned char b24; char pad2[3]; int i28; char pad3[4]; };
extern "C" {
extern char D_004EE550[];
extern char D_004D9340[];
void cNPC_v3D(Npc2CA0* o);
void Event_Construct(Ev2CA0* e, void* type);
void NpcAi_ModeFollow(Npc2CA0* o, Ev2CA0* e);
void cMessage_dtor(void* self, int flags);
}
extern "C" void cNetNPC_NetFollow(Npc2CA0* o, bool on)
{
    if (on) {
        Ev2CA0 ev;
        cNPC_v3D(o);
        Event_Construct(&ev, D_004EE550);
        ev.vtable = D_004D9340;
        ev.b24 = 0;
        ev.i28 = -1;
        NpcAi_ModeFollow(o, &ev);
        ev.vtable = D_004D9340;
        cMessage_dtor(&ev, 0);
        o->bits.f0 = 1;
    } else {
        o->bits.f0 = 0;
    }
}