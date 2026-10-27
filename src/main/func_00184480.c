#include "types.h"

typedef struct {
    void* vtable;
    char base[0x20];
    unsigned char flag;
    char pad[0xB];
    char xform[0x40];
} PosMsg;
extern char D_0055D4D8[];
extern char D_004D9DA0[];
extern void cMessage_ctor_cMessageNameR(PosMsg* msg, void* name);
extern int cMoveMsg_Template_HasDeltaPosition(PosMsg* msg);
extern Vec4* func_00133EC0(void* xform);
extern void cVector_Copy_WSet0(Vec4* out, Vec4* v);
extern void cVector_Copy_WSet1(Vec4* out, Vec4* v);
extern void cMatrix_ctor_cMatrixR_cVectorR(void* dst, void* basis, Vec4* pos);
extern void QueueMessage_cMessageR_cSystemP_int(PosMsg* msg, void* target, int flags);
extern void cMessage_dtor(PosMsg* msg, int flags);

/* Sends target a transform message built from xform (translation as a direction or a point). */
void cHuman_SetRotation(void* target, void* xform)
{
    Vec4 point;
    Vec4 dir;
    PosMsg msg;
    PosMsg* m = &msg;
    Vec4* pos;
    cMessage_ctor_cMessageNameR(m, D_0055D4D8);
    m->vtable = D_004D9DA0;
    m->flag = 1;
    if (cMoveMsg_Template_HasDeltaPosition(m)) {
        cVector_Copy_WSet0(&dir, func_00133EC0(xform));
        pos = &dir;
    } else {
        cVector_Copy_WSet1(&point, func_00133EC0(xform));
        pos = &point;
    }
    cMatrix_ctor_cMatrixR_cVectorR(m->xform, xform, pos);
    QueueMessage_cMessageR_cSystemP_int(&msg, target, 1);
    msg.vtable = D_004D9DA0;
    cMessage_dtor(&msg, 0);
}
