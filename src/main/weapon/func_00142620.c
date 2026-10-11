#include "types.h"
typedef struct { void* vt; char pad[0x18]; int size; unsigned char kind; char pad21[0xB]; unsigned char b2C; char pad2D[7]; unsigned char slot; char pad35[3]; int amount; char pad3C[4]; } Ev_2620;
typedef struct { int pad0; int id; int x8; int count; } Slot_2620;
typedef struct { int pad0; Slot_2620 slots[8]; unsigned char cur; char pad85[3]; void* own; } S_2620;
typedef struct { char pad[0x18]; int x18; } H_2620;
extern unsigned char D_005721C8;
extern char D_0052ACC8[];
extern char D_004DE610[];
void Event_Construct(Ev_2620* e, void* type);
void Event_Send(Ev_2620* e, void* target, int a);
void cMessage_dtor(Ev_2620* e, int f);
int func_00142620(S_2620* self, int slot, int amount, int remote)
{
    unsigned char dbl;
    Slot_2620* s;
    int max;
    int n;
    int dec;
    dbl = (unsigned char)slot == 0 && !(~((H_2620*)self)->x18 == 0);
    s = &self->slots[(unsigned char)slot];
    if (dbl)
        max = s->count * 2;
    else
        max = s->count;
    n = amount < max ? amount : max;
    if (dbl)
        dec = n / 2;
    else
        dec = n;
    s->count -= dec;
    if (D_005721C8 && !remote) {
        Ev_2620 e;
        Event_Construct(&e, D_0052ACC8);
        e.slot = slot;
        e.amount = n;
        e.vt = D_004DE610;
        e.b2C = 1;
        e.size = 0x40;
        e.kind = 4;
        Event_Send(&e, self->own, 0);
        e.vt = D_004DE610;
        cMessage_dtor(&e, 0);
    }
    return n;
}