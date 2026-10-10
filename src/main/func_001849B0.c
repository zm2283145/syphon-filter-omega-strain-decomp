#include "types.h"
typedef struct { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; } Msg;
extern char D_0055D4E0[];
extern char D_004D9360[];
extern void Event_Construct(Msg* m, void* type);
extern int func_0015A430(Msg* m);
extern void* func_0014B210(void);
extern void func_0015A400(Vec4* out, void* v);
extern void func_0014B1E0(Vec4* out, void* v);
extern void func_0014B160(void* data, void* obj, Vec4* v);
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
    Event_Construct(m, D_0055D4E0);
    msg.vtable = D_004D9360;
    msg.kind = 0;
    if (func_0015A430(m)) {
        func_0015A400(&a, pos);
        v = &a;
    } else {
        func_0014B1E0(&b, pos);
        v = &b;
    }
    func_0014B160(m->data, func_0014B210(), v);
    Event_Send(&msg, target, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(&msg, 0);
}