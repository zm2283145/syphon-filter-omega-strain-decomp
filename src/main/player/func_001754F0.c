#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad[0xB];
    int a;
} Msg_RB;
typedef struct { char pad[0xC]; int id; char pad2[0x4C - 0x10]; int kind; } Plr_RB;
extern char D_004F80A8[];
extern void Message_GetScriptTypeKey();
extern void func_001755D0();
extern void func_0025DDE0();
extern void func_0025E080();
void * const D_004DC7D0[8] = { (void*)0x0, (void*)0x0, (void*)func_001755D0, (void*)func_0025DDE0, (void*)func_0025E080, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
extern int D_0049D010;
extern void Event_Construct(Msg_RB* msg, void* name);
extern void Event_Send(Msg_RB* msg, void* target, int flags);
extern void cMessage_dtor(Msg_RB* msg, int flags);
extern Plr_RB* GObj_IdentityB(void* o);
int Script_RestoreBody(void** args)
{
    Plr_RB* p = GObj_IdentityB(args[0]);
    if (p->kind == D_0049D010) {
        Msg_RB m1;
        Msg_RB m2;
        Event_Construct(&m1, D_004F80A8);
        m1.vtable = ((char*)D_004DC7D0);
        m1.a = p->id;
        m1.kind = 0x15;
        m1.x1C = 0x40;
        Event_Construct(&m2, D_004F80A8);
        m2.vtable = ((char*)D_004DC7D0);
        m2.a = p->id;
        Event_Send(&m2, p, 0);
        m2.vtable = ((char*)D_004DC7D0);
        cMessage_dtor(&m2, 0);
        m1.vtable = ((char*)D_004DC7D0);
        cMessage_dtor(&m1, 0);
    }
    return 0;
}