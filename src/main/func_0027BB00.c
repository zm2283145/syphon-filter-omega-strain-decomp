#include "types.h"

typedef struct { void* vtable; char data[0x20]; unsigned char mode; char pad[3]; int unk28; char pad2[0x24]; } Visitor;

extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
extern void cNetTaserMsg_UnpackAndProcess(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor (mode 2) on the stack, applies it to self and destroys it. */
void cNetTaserMsg_NetReceive(void* self)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_00504050);
    v.vtable = D_004DCDA0;
    v.mode = 2;
    v.unk28 = 0;
    cNetTaserMsg_UnpackAndProcess(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
