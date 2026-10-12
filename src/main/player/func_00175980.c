#include "types.h"
#pragma global_optimizer off
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int count;
} Msg_SM;
typedef struct { char pad[0x14]; unsigned char local; } Ctl_SM;
typedef struct { char pad[0x30]; Ctl_SM* ctl; char pad2[0x1B8 - 0x34]; int maxNpc; } Plr_SM;
extern char D_004F53F8[];
extern void Message_GetScriptTypeKey();
extern void cMaxActiveNpcCountMsg_dtor();
extern void cMaxActiveNpcCountMsg_v01();
extern void cMaxActiveNpcCountMsg_v04();
extern void cMaxActiveNpcCountMsg_v05();
extern void func_002823E0();
void * const D_004DAE70[8] = { (void*)0x0, (void*)0x0, (void*)cMaxActiveNpcCountMsg_dtor, (void*)cMaxActiveNpcCountMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cMaxActiveNpcCountMsg_v04, (void*)cMaxActiveNpcCountMsg_v05 };
extern char D_004DCF10[];
extern void Event_Construct(Msg_SM* msg, void* name);
extern void Event_Send(Msg_SM* msg, void* target, int flags);
extern void cMessage_dtor(Msg_SM* msg, int flags);
static inline void SetMax(int n, Plr_SM* p)
{
    if (p->ctl->local) {
        p->maxNpc = n;
    } else {
        Msg_SM msg;
        Event_Construct(&msg, D_004F53F8);
        msg.count = n;
        msg.vtable = ((char*)D_004DAE70);
        msg.kind = 8;
        Event_Send(&msg, p->ctl, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
int Script_cPlayer_SetMaxActiveNpcCount(int* args)
{
    int n[1];
    n[0] = args[1];
    SetMax(*(int*)n, (Plr_SM*)args[0]);
    return 0;
}