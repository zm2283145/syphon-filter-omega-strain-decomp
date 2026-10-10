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
extern void Event_Construct(PosMsg* msg, void* name);
extern int func_00184470(PosMsg* msg);
extern Vec4* func_00133EC0(void* xform);
extern void func_0015A400(Vec4* out, Vec4* v);
extern void func_0014B1E0(Vec4* out, Vec4* v);
extern void func_0014B160(void* dst, void* basis, Vec4* pos);
extern void Event_Send(PosMsg* msg, void* target, int flags);
extern void cMessage_dtor(PosMsg* msg, int flags);

/* Sends target a transform message built from xform (translation as a direction or a point). */
void func_00184480(void* target, void* xform)
{
    Vec4 point;
    Vec4 dir;
    PosMsg msg;
    PosMsg* m = &msg;
    Vec4* pos;
    Event_Construct(m, D_0055D4D8);
    m->vtable = D_004D9DA0;
    m->flag = 1;
    if (func_00184470(m)) {
        func_0015A400(&dir, func_00133EC0(xform));
        pos = &dir;
    } else {
        func_0014B1E0(&point, func_00133EC0(xform));
        pos = &point;
    }
    func_0014B160(m->xform, xform, pos);
    Event_Send(&msg, target, 1);
    msg.vtable = D_004D9DA0;
    cMessage_dtor(&msg, 0);
}
