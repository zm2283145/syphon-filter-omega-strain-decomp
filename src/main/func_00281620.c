#include "types.h"

typedef struct { void* vtable; char data[0x2C]; } Visitor;

extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
extern void Event_Construct(Visitor* v, void* arg);
extern void func_00281680(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor on the stack, applies it to self and destroys it. */
void func_00281620(void* self)
{
    Visitor v;
    Event_Construct(&v, D_005061B0);
    v.vtable = D_004DCEF0;
    func_00281680(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
