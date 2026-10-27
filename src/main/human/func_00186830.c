#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_6830 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Hum_6830 { char pad[0x14]; unsigned char alive; char pad15[0x43]; Ctl_6830* ctl; char pad5c[0x33A8 - 0x5C]; float blind; };
struct Msg_6830 { void* vt; char pad[0x1C]; unsigned char kind; char pad21[3]; int id; unsigned char sub; char pad29[3]; float v; };
extern "C" {
void ScreenFx_Start(void*, int, float, float, float, float);
void cMessage_ctor_cMessageNameR(Msg_6830*, void*);
void QueueMessage_cMessageR_cSystemP_int(Msg_6830*, void*, int);
void cMessage_dtor(Msg_6830*, int);
extern void* g_VisionFxMan;
extern float D_0048A2C8;
extern unsigned char g_IsMultiplayer;
extern char g_ActorActionMsgClass[];
extern char D_004E01C0[];
extern char D_004E0840[];
}
static inline unsigned char IsPlayer_6830(Hum_6830* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
/* blind an actor: store the amount, flash the screen for the player, broadcast */
#pragma push
#pragma opt_propagation off
extern "C" void cHuman_SetBlinded(Hum_6830* h, int silent, float v)
{
    h->blind = v;
    if (h->alive && IsPlayer_6830(h)) ScreenFx_Start(g_VisionFxMan, 1, 0.0f, D_0048A2C8, v, v);
    if (g_IsMultiplayer && !silent) {
        Msg_6830 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.id = 0x45;
        m.sub = 3;
        m.vt = D_004E01C0;
        m.kind = 4;
        m.v = v;
        QueueMessage_cMessageR_cSystemP_int(&m, h, 0);
        m.vt = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
#pragma pop
