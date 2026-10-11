#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int state; signed char b28; char pad29[3]; } Msg_21CB90;
typedef struct { char pad[0xD1]; unsigned char paused; } Gen_21CB90;
extern unsigned char D_005721C8;
extern char D_004A4A78[];
extern char D_004DB5E0[];
extern void Event_Construct(Msg_21CB90* m, void* type);
extern void Event_Send(Msg_21CB90* m, void* target, int x);
extern void cMessage_dtor(Msg_21CB90* m, int f);
int Script_cGenerator_Pause(Gen_21CB90** args)
{
    unsigned char st;
    Gen_21CB90* g;
    g = args[0];
    g->paused = 1;
    if (D_005721C8) {
        Msg_21CB90 m;
        st = g->paused;
        Event_Construct(&m, D_004A4A78);
        m.state = st;
        m.b28 = 0;
        m.vt = D_004DB5E0;
        m.kind = 4;
        Event_Send(&m, g, 0);
        m.vt = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}