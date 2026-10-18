#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
struct Ctl_E930 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
struct Ent_E930 { char pad[0xC]; unsigned int h; char pad10[0x48]; Ctl_E930* ctl; };
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[3]; int key; int flag; char pad2C[4]; } Msg_E930;
extern "C" {
extern char D_00586158[];
extern char D_004E1680[];
int Loc_FindKeyThunk(char* s);
extern char D_004DCF10[];
void Event_Construct(Msg_E930* m, void* type);
void Transport_Send(int to, Msg_E930* m, int a, int b);
void cMessage_dtor(Msg_E930* m, int flags);
void GameScreen_DisplayInteractLocal(char* text, unsigned char flag);
}
static inline int OwnerOf_E930(Ent_E930* e)
{
    if (D_005721C8) {
        unsigned char ok = 0;
        Ctl_E930* c = e->ctl;
        if (c && c->isNet()) ok = 1;
        if (ok) return ((e->h & 0x7F000000) >> 24) - 1;
        return -1;
    }
    return 0;
}
static inline void Msg_Init_E930(Msg_E930* p, char* text, unsigned char flag)
{
    p->key = Loc_FindKeyThunk(text);
    p->flag = flag;
}
#pragma opt_propagation off
extern "C" void Global_DisplayInteract_2(Ent_E930* e, char* text, unsigned char flag)
{
    Msg_E930 m;
    if (D_005721C8) {
        Msg_E930* p = &m;
        Event_Construct(p, D_00586158);
        m.vt = D_004E1680;
        Msg_Init_E930(p, text, flag);
        m.f1C = 0x40;
        if (!e) {
            m.f20 = 4;
            Transport_Send(0, &m, -1, -1);
            GameScreen_DisplayInteractLocal(text, flag);
        } else {
            int own = OwnerOf_E930(e);
            if (own != NetLocalId()) Transport_Send(0, &m, 0, own);
            else GameScreen_DisplayInteractLocal(text, flag);
        }
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    } else {
        GameScreen_DisplayInteractLocal(text, flag);
    }
}