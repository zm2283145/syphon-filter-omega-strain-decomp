/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Door: only the slots used here are named (vtable offset in comments). */
struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(int flag); /* +0x60 */
};

typedef struct cElevatorGOBJ {
    char pad[0x64];
    Door* door; /* +0x64 */
    char pad68[0x2E0 - 0x68];
    int floors; /* +0x2E0 */
} cElevatorGOBJ;

/* Elevator notification message built on the stack (0x1D0 bytes); its destructor is inlined. */
typedef struct ElevatorMsg {
    void* vtable;           /* +0x000 */
    char pad004[0x78 - 4];
    char memberA[0x114 - 0x78]; /* +0x078 */
    char memberB[0x1D0 - 0x114]; /* +0x114 */
} ElevatorMsg;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004F77C0[];
extern "C" void func_0020EBA0(ElevatorMsg* msg, int* floors, cElevatorGOBJ* self);
extern "C" void Event_Send(ElevatorMsg* msg, void* queue, int flag);
extern "C" void func_0036E220(void* member, int flag);
extern "C" void cMessage_dtor(ElevatorMsg* msg, int flag);
extern "C" void func_0022C720(void* list, cElevatorGOBJ* obj);
extern "C" void func_003CE7D0(cElevatorGOBJ* self);

/* Lift virtual 0x07: posts an elevator message, notifies the door (virtual +0x60), runs the base handler and unregisters. */
extern "C" void cElevatorGOBJ_v07(cElevatorGOBJ* self)
{
    ElevatorMsg msg;
    func_0020EBA0(&msg, &self->floors, self);
    Event_Send(&msg, D_004FFB50, 1);
    /* ~ElevatorMsg() */
    msg.vtable = D_004DADF0;
    func_0036E220(msg.memberB, -1);
    func_0036E220(msg.memberA, -1);
    cMessage_dtor(&msg, 0);
    if (self->door)
        self->door->Method60(1);
    func_003CE7D0(self);
    func_0022C720(D_004F77C0, self);
}
