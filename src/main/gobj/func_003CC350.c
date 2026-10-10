#include "types.h"

typedef struct { void* vtable; char data[0x18]; int size; char pad[4]; int index; char pad2[8]; } Visitor;
typedef struct { char pad[0x64]; unsigned char flag; } SubScript;

extern char D_0055D4B8[];
extern char D_004E0880[];
extern void Event_Construct(Visitor* v, void* arg);
extern void Event_Send(Visitor* v, void* target, int flags);
extern void cMessage_dtor(Visitor* v, int flags);

/* SubScript virtual 0x17: sets the flag and applies a temporary visitor to self. */
void SubScript_v17(SubScript* self)
{
    Visitor v;
    self->flag = 1;
    Event_Construct(&v, D_0055D4B8);
    v.vtable = D_004E0880;
    v.index = -1;
    v.size = 0x40;
    Event_Send(&v, self, 0);
    v.vtable = D_004E0880;
    cMessage_dtor(&v, 0);
}
