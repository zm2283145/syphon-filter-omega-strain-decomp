#include "types.h"
typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; } Msg;
extern char D_0055D4D8[];
extern char D_004D9DA0[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern int cMoveMsg_Template_HasDeltaPosition(Msg* m);
extern void* cMatrix_GetUnit(void);
extern void cVector_Copy_WSet0(Vec4* out, void* v);
extern void cVector_Copy_WSet1(Vec4* out, void* v);
extern void cMatrix_ctor_cMatrixR_cVectorR(void* data, void* obj, Vec4* v);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a kind-0 message with a position to target. */
void cHuman_SetTranslation(void* target, void* pos)
{
    Vec4 b;
    Vec4 a;
    Msg msg;
    Vec4* v;
    Msg* m = &msg;
    cMessage_ctor_cMessageNameR(m, D_0055D4D8);
    msg.vtable = D_004D9DA0;
    msg.kind = 0;
    if (cMoveMsg_Template_HasDeltaPosition(m)) {
        cVector_Copy_WSet0(&a, pos);
        v = &a;
    } else {
        cVector_Copy_WSet1(&b, pos);
        v = &b;
    }
    cMatrix_ctor_cMatrixR_cVectorR(m->data, cMatrix_GetUnit(), v);
    QueueMessage_cMessageR_cSystemP_int(&msg, target, 1);
    msg.vtable = D_004D9DA0;
    cMessage_dtor(&msg, 0);
}