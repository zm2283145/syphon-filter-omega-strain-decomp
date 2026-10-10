#include "types.h"

typedef struct { void* vtable; char data[0x20]; unsigned char mode; char pad[3]; int unk28; char pad2[0x24]; } Visitor;

extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern void Event_Construct(Visitor* v, void* arg);
extern void func_0027BB70(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor (mode 2) on the stack, applies it to self and destroys it. */
void func_0027BB00(void* self)
{
    Visitor v;
    Event_Construct(&v, D_00504050);
    v.vtable = D_004DCDA0;
    v.mode = 2;
    v.unk28 = 0;
    func_0027BB70(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
