#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad[0xB];
    int a;
    int b;
} Msg_SB;
typedef struct { char pad[0xC]; int id; char pad2[0x4C - 0x10]; int kind; } Plr_SB;
typedef struct { char pad[0xC]; int id; char pad2[0x30 - 0x10]; Plr_SB* ctl; } GObj_SB;
extern char D_004F80B8[];
extern char D_004DC7F0[];
extern int g_HumanActorClassKey;
extern void Event_Construct(Msg_SB* msg, void* name);
extern void Event_Send(Msg_SB* msg, void* target, int flags);
extern void cMessage_dtor(Msg_SB* msg, int flags);
extern GObj_SB* NpcScript_GetReceiver(void* o);
extern GObj_SB* GObj_IdentityB(void* o);extern GObj_SB* g_LocalPlayer;
int Script_SwitchBodies(void** args)
{
    GObj_SB* b;
    Plr_SB* a;
    Plr_SB* bp;
    b = NpcScript_GetReceiver(args[0]);
    bp = b->ctl;
    a = g_LocalPlayer->ctl;
    if (a->kind == g_HumanActorClassKey && bp->kind == g_HumanActorClassKey) {
        Msg_SB msg;
        Event_Construct(&msg, D_004F80B8);
        msg.vtable = D_004DC7F0;
        msg.a = a->id;
        msg.b = b->ctl->id;
        msg.kind = 0x15;
        msg.x1C = 0x40;
        Event_Send(&msg, a, 0);
        msg.vtable = D_004DC7F0;
        cMessage_dtor(&msg, 0);
    }
    return 0;
}