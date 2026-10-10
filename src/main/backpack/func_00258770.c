#include "types.h"

typedef struct { void* vtable; char data[0x2C]; } Visitor; /* 0x30-byte stack object */
extern char D_004F7EE0[];
extern char D_004DC460[]; /* visitor vtable */
extern char D_004DCF10[]; /* base vtable */
extern void Event_Construct(Visitor* v, const char* name);
extern void func_00258480(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Runs a temporary visitor object over target. */
void func_00258770(void* target)
{
    Visitor v;
    Event_Construct(&v, D_004F7EE0);
    v.vtable = D_004DC460;
    func_00258480(&v, target);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
