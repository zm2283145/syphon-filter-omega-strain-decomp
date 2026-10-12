#include "types.h"
typedef struct { void* vtable; char pad4[0x1C]; unsigned char type; char pad21[0xF]; } Msg00232730;
typedef struct { char pad[0x30]; void* target; } Net00232730;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern Net00232730* D_004FFC0C;
extern char D_004DCF10[];
extern void func_00232BF0(int a, int b, float c, float d, float e, float f);
extern void cAtmosphericEffectMsg_ctor(Msg00232730* ev, int kind);
extern void Event_Send(Msg00232730* ev, void* target, int flags);
extern void cMessage_dtor(Msg00232730* ev, int flags);
/* Script global: Myanmar fog effect. */
void Global_FogMyanmar(void)
{
    func_00232BF0(0x14, -1, 20.0f, 0.0f, 40.0f, 0.4f);
    if (D_005721C8 && (D_005721C8 ? D_005721C0 : 1)) {
        Msg00232730 ev;
        Net00232730* net = D_004FFC0C;
        cAtmosphericEffectMsg_ctor(&ev, 4);
        ev.type = 4;
        Event_Send(&ev, net->target, 0);
        ev.vtable = D_004DCF10;
        cMessage_dtor(&ev, 0);
    }
}
