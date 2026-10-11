#include "types.h"
typedef struct { void* vtable; char pad04[0x1C]; char kind; char pad21[7]; char op; char pad29[3]; } Msg0021C9A0;
typedef struct { char pad[0xC0]; int pulse; } Gen0021C9A0;
extern unsigned char D_005721C8;
extern char D_004A4A78[];
extern char D_004DB5E0[];
extern void Event_Construct(Msg0021C9A0* m, void* name);
extern void Event_Send(Msg0021C9A0* m, void* target, int a);
extern void cMessage_dtor(Msg0021C9A0* m, int flags);
int Script_cGenerator_ResetPulse(Gen0021C9A0** args)
{
    Gen0021C9A0* g = *args;
    g->pulse = 0;
    if (D_005721C8) {
        Msg0021C9A0 m;
        Event_Construct(&m, D_004A4A78);
        m.vtable = D_004DB5E0;
        m.op = 2;
        m.kind = 4;
        Event_Send(&m, g, 0);
        m.vtable = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}