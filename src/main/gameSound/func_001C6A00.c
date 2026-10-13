#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "sound_event.h"
struct Ctl_6890 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_6890 { char pad[0xC]; unsigned int flags; char pad10[4]; unsigned char b14; char pad15[0x43]; Ctl_6890* ctl; };
extern "C" {
extern char D_004FFB50[];
extern char D_004DAE30[];
extern unsigned char D_005721C8;
void EffectMsg_WrapRequest(void*, void*);
void Transport_Send(int, void*, int, int);
void Global_PlayMusic(const char* name, Hum_6890* h);
}
static inline unsigned char IsPlayer_6890(Hum_6890* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_6890(Hum_6890* h) { int id; if (D_005721C8) { if (IsPlayer_6890(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
extern "C" void Global_PlayMusic(const char* name, Hum_6890* h)
{
    SoundEventP ev;
    SoundRequest req;
    SoundRequest_Ctor(&req, 5, name, 0, 0);
    EffectMsg_WrapRequest(&ev, &req);
    func_0036E220(&req.b, -1);
    func_0036E220(&req.a, -1);
    if (D_005721C8) {
        if (h->b14) {
            ev.kind = 1;
            Event_Send(&ev, D_004FFB50, 0);
        } else {
            Transport_Send(0, &ev, 0, LocalId_6890(h));
        }
    } else {
        Event_Send(&ev, D_004FFB50, 0);
    }
    ev.vtable = D_004DAE30;
    func_0036E220(&ev.req.b, -1);
    func_0036E220(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
}
