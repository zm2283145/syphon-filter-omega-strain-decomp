#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_2B0F00 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_2B0F00 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_2B0F00* ctl; };
struct Msg_2B0F00 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int f24; int f28; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char g_Game[];
extern char D_0052ACD8[];
extern char D_004DE630[];
extern char D_004DCF10[];
int nGlobalization_GetStringIndex(int key);
void cGameSystem_SetClientPlayerLocation(void* list, int id, int key);
void cMessage_ctor_cMessageNameR(Msg_2B0F00* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(Msg_2B0F00* m, Hum_2B0F00* h, int a);
void cMessage_dtor(Msg_2B0F00* m, int flags);
}
static inline unsigned char IsPlayer_2B0F00(Hum_2B0F00* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_2B0F00(Hum_2B0F00* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_2B0F00(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
extern "C" void Global_SetLocation(Hum_2B0F00* h, int key)
{
    if (!h || LocalId_2B0F00(h) < 0 || LocalId_2B0F00(h) >= 4)
        return;
    key = nGlobalization_GetStringIndex(key);
    cGameSystem_SetClientPlayerLocation(g_Game, LocalId_2B0F00(h), key);
    if (g_IsMultiplayer) {
        Msg_2B0F00 m;
        cMessage_ctor_cMessageNameR(&m, D_0052ACD8);
        m.vtable = D_004DE630;
        m.f24 = -1;
        m.b20 = 8;
        m.f28 = key;
        QueueMessage_cMessageR_cSystemP_int(&m, h, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}

