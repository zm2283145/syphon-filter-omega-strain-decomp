#include "types.h"
typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; } Msg;
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
extern void Event_Construct(Msg* m, void* type);
extern int TeleportMsg_IsMode3(Msg* m);
extern void* func_00133EC0(void* obj);
extern void cVector_Copy_WSet0(Vec4* out, void* v);
extern void Vec4_CopyAsPoint(Vec4* out, void* v);
extern void Mtx_SetRotationTranslation(void* data, void* obj, Vec4* v);
extern void Event_Send(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a kind-2 message describing obj's position to target. */
void Npc_v29(void* target, void* obj)
{
    Vec4 b;
    Vec4 a;
    Msg msg;
    Msg* m = &msg;
    Vec4* v;
    Event_Construct(m, g_TeleportMsgClass);
    msg.vtable = D_004D9360;
    msg.kind = 2;
    if (TeleportMsg_IsMode3(m)) {
        cVector_Copy_WSet0(&a, func_00133EC0(obj));
        v = &a;
    } else {
        Vec4_CopyAsPoint(&b, func_00133EC0(obj));
        v = &b;
    }
    Mtx_SetRotationTranslation(m->data, obj, v);
    Event_Send(&msg, target, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(&msg, 0);
}
