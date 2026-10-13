
#include "types.h"
typedef struct { void* vt; char pad04[0x18]; int x1C; char pad20[4]; int cat; signed char kind; char pad29[3]; int id; int x30; float val; unsigned char flag; char pad39[3]; } Msg_3E67C0;
typedef struct { char pad0[0x30]; void* owner; } Pt2_Tgt;
typedef struct { char pad0[0xC]; int id; } Pt2_Hd;
extern int D_0055A840;
const float D_00493938[2] = { -1.0f, 0.0f };
const float D_00493940[2] = { -2.0f, 0.0f };
extern char D_0055D480[];
extern char D_004E0160[];
extern char D_004E0840[];
extern int* Receiver_GetOwner(void);
extern void Event_Construct(Msg_3E67C0* m, void* type);
extern void Event_Send(Msg_3E67C0* m, void* target, int x);
extern void cMessage_dtor(Msg_3E67C0* m, int f);

void ObjectAction_SendKind7(Pt2_Tgt* t, char cat, Pt2_Hd* h, unsigned char flag, float val) {
    int tmp[1];
    int* idp;
    Msg_3E67C0 m;
    { int k = *Receiver_GetOwner(); if (k == D_0055A840) t = (Pt2_Tgt*)t->owner; }
    if (val == (*(float*)D_00493938)) val = -1.0f;
    else if (val == (*(float*)D_00493940)) val = 3.4028235e38f;
    if (h) idp = &h->id;
    else { tmp[0] = -1; idp = tmp; }
    Event_Construct(&m, D_0055D480);
    m.cat = cat;
    m.kind = 7;
    m.vt = D_004E0160;
    m.id = *idp;
    m.val = val;
    m.x30 = -1;
    m.x1C = 0x40;
    m.flag = flag;
    Event_Send(&m, t, 0);
    m.vt = D_004E0840;
    cMessage_dtor(&m, 0);
}