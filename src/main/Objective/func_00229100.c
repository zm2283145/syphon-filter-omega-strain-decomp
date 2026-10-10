#include "types.h"

typedef struct { void* vtable; char data[0x2C]; } Visitor;
typedef struct { char pad[0x10]; void* target; char pad2[0x11]; unsigned char active; } Objective;

extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
extern char D_00572198[];
extern char D_004E0E80[];
extern void Event_Construct(Visitor* v, void* arg);
extern void func_00429200(Visitor* v, void* target, int flags);
extern void cMessage_dtor(Visitor* v, int flags);

/* Deactivates the objective and, when both global flags are set, notifies its target. */
void Objective_Deactivate(Objective* self)
{
    self->active = 0;
    if (D_005721C8 && D_005721D0) {
        Visitor v;
        Event_Construct(&v, D_00572198);
        v.vtable = D_004E0E80;
        func_00429200(&v, self->target, -1);
        v.vtable = D_004E0E80;
        cMessage_dtor(&v, 0);
    }
}
