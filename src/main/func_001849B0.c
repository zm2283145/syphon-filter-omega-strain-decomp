#include "types.h"
typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; } Msg;
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
extern void Event_Construct(Msg* m, void* type);
extern int TeleportMsg_IsMode3(Msg* m);
extern void* Mtx_GetIdentity(void);
extern void func_0015A400(Vec4* out, void* v);
extern void Vec4_CopyAsPoint(Vec4* out, void* v);
extern void Mtx_SetRotationTranslation(void* data, void* obj, Vec4* v);
extern void Event_Send(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a kind-0 message with a position to target. */
void func_001849B0(void* target, void* pos)
{
    Vec4 b;
    Vec4 a;
    Msg msg;
    Vec4* v;
    Msg* m = &msg;
    Event_Construct(m, g_TeleportMsgClass);
    msg.vtable = D_004D9360;
    msg.kind = 0;
    if (TeleportMsg_IsMode3(m)) {
        func_0015A400(&a, pos);
        v = &a;
    } else {
        Vec4_CopyAsPoint(&b, pos);
        v = &b;
    }
    Mtx_SetRotationTranslation(m->data, Mtx_GetIdentity(), v);
    Event_Send(&msg, target, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(&msg, 0);
}