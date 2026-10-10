#include "types.h"

typedef struct { void* vtable; char data[0x2C]; } Visitor;

extern char D_004F7BE8[];
extern char D_004DBB40[];
extern char D_004DCF10[];
extern void Event_Construct(Visitor* v, void* arg);
extern void cNetSpawnParticleMsg_Receive(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor on the stack, applies it to self and destroys it. */
void func_00230C80(void* self)
{
    Visitor v;
    Event_Construct(&v, D_004F7BE8);
    v.vtable = D_004DBB40;
    cNetSpawnParticleMsg_Receive(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
