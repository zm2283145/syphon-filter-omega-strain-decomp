#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char x20; int x24; unsigned char x28; char pad2[7]; } Ev24A7A0;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(Ev24A7A0*, void*);
extern void Event_Send(Ev24A7A0*, void*, int);
extern void cMessage_dtor(void*, int);
int func_0024A7A0(void* self, void* target) {
    Ev24A7A0 ev;
    Event_Construct(&ev, D_0055D480);
    ev.vt = D_004E0840;
    ev.x24 = 9;
    ev.x20 = 1;
    ev.x28 = 0;
    Event_Send(&ev, target, 1);
    ev.vt = D_004E0840;
    cMessage_dtor(&ev, 0);
    return 1;
}