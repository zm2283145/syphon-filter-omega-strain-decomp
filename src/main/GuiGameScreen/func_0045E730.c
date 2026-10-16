#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Ctl_E730 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
struct Ent_E730 { char pad[0xC]; unsigned int h; char pad10[0x48]; Ctl_E730* ctl; };
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[0xF]; } Msg_E730;
extern "C" {
extern char D_00586170[];
extern "C" void Message_GetScriptTypeKey();
extern "C" void cClearClientInteractMsg_dtor();
extern "C" void cClearClientInteractMsg_v01();
extern "C" void cClearClientInteractMsg_v04();
extern "C" void cClearClientInteractMsg_v05();
extern "C" void func_002823E0();
void * const D_004E16A0[8] = { (void*)0x0, (void*)0x0, (void*)cClearClientInteractMsg_dtor, (void*)cClearClientInteractMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cClearClientInteractMsg_v04, (void*)cClearClientInteractMsg_v05 };
extern char D_004DCF10[];
void Event_Construct(Msg_E730* m, void* type);
void Transport_Send(int to, Msg_E730* m, int a, int b);
void cMessage_dtor(Msg_E730* m, int flags);
void GameScreen_ClearInteractLocal(void);
}
static inline int OwnerOf_E730(Ent_E730* e)
{
    if (D_005721C8) {
        unsigned char ok = 0;
        Ctl_E730* c = e->ctl;
        if (c && c->isNet()) ok = 1;
        if (ok) return ((e->h & 0x7F000000) >> 24) - 1;
        return -1;
    }
    return 0;
}
extern "C" void Global_ClearInteract(Ent_E730* e)
{
    Msg_E730 m;
    if (D_005721C8) {
        Event_Construct(&m, D_00586170);
        m.vt = ((char*)D_004E16A0);
        m.f1C = 0x40;
        if (!e) {
            m.f20 = 4;
            Transport_Send(0, &m, -1, -1);
            GameScreen_ClearInteractLocal();
        } else {
            int own = OwnerOf_E730(e);
            if (own != NetLocalId()) Transport_Send(0, &m, 0, own);
            else GameScreen_ClearInteractLocal();
        }
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    } else {
        GameScreen_ClearInteractLocal();
    }
}