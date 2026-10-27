#include "types.h"
typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; } Msg;
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern int cMoveMsg_Template_1_HasDeltaPosition(Msg* m);
extern void* func_00133EC0(void* obj);
extern void cVector_Copy_WSet0(Vec4* out, void* v);
extern void cVector_Copy_WSet1(Vec4* out, void* v);
extern void cMatrix_ctor_cMatrixR_cVectorR(void* data, void* obj, Vec4* v);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a kind-1 message describing obj's position to target. */
void cHuman_SetRotation_ResetPhysics(void* target, void* obj)
{
    Vec4 b;
    Vec4 a;
    Msg msg;
    Msg* m = &msg;
    Vec4* v;
    cMessage_ctor_cMessageNameR(m, g_TeleportMsgClass);
    msg.vtable = D_004D9360;
    msg.kind = 1;
    if (cMoveMsg_Template_1_HasDeltaPosition(m)) {
        cVector_Copy_WSet0(&a, func_00133EC0(obj));
        v = &a;
    } else {
        cVector_Copy_WSet1(&b, func_00133EC0(obj));
        v = &b;
    }
    cMatrix_ctor_cMatrixR_cVectorR(m->data, obj, v);
    QueueMessage_cMessageR_cSystemP_int(&msg, target, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(&msg, 0);
}
