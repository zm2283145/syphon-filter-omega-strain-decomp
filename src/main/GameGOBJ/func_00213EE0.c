#include "types.h"
typedef struct MsgLC {
    void* vtable;
    char base[0x20];
    int f24;
    int f28;
    char pad[4];
} MsgLC;
extern char D_004F5448[];
extern char D_004DAED0[];
extern int func_00214080(void* lift);
extern unsigned char func_00214470(void* lift);
extern int func_00213FE0(void* lift);
extern void func_00214310(void* lift);
extern void Event_Construct(MsgLC* msg, void* name);
extern void Event_Send(MsgLC* msg, void* target, int flags);
extern void cMessage_dtor(MsgLC* msg, int flags);
unsigned char Lift_CloseDoors(void* lift)
{
    unsigned char r = 1;
    if (func_00214080(lift)) {
        r = func_00214470(lift);
        if (r) {
            MsgLC msg;
            Event_Construct(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.f24 = 3;
            msg.f28 = 0;
            Event_Send(&msg, lift, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
    }
    if (func_00213FE0(lift)) {
        func_00214310(lift);
    }
    return r;
}