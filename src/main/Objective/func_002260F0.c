#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int f1C;
    unsigned char b20;
    char pad21[0xB];
    unsigned char b2C;
    char pad2D[3];
    int f30;
    char pad34[0x10];
} E7FMsg;
typedef struct { char pad[0x4C]; int type; } E7FActor;
extern unsigned char D_005721C8;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
extern int D_0049D010;
extern void Event_Construct(E7FMsg* msg, void* name);
extern void Event_Send(E7FMsg* msg, void* target, int flags);
extern void cMessage_dtor(E7FMsg* msg, int flags);
extern void Objective_SetFailed(void* obj);
extern void func_0018C770(E7FActor* a, int n);
void Objective_Fail(void* self, void* obj, E7FActor* actor)
{
    if (D_005721C8) {
        E7FMsg msg;
        Event_Construct(&msg, D_0051F0B0);
        msg.vtable = D_004DE4F0;
        msg.b2C = 0;
        msg.f30 = -1;
        msg.f1C = 0x40;
        msg.b20 = 4;
        Event_Send(&msg, obj, 0);
        msg.vtable = D_004DE4F0;
        cMessage_dtor(&msg, 0);
    }
    Objective_SetFailed(obj);
    if (actor && actor->type == D_0049D010) {
        func_0018C770(actor, 11);
    }
}
