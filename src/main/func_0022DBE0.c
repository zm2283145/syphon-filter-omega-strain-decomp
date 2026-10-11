#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB890[];
extern "C" char D_004A67C8[];

struct Msg_0022DBE0 : ClonedMessageBase {
    int a24;
};

extern "C" Msg_0022DBE0* cRespawnMsg_v01(Msg_0022DBE0* self)
{
    Msg_0022DBE0* p;
    {
        AllocGuard guard;
        p = (Msg_0022DBE0*)Mem_Alloc(0, 40, D_004A67C8, 107);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w04 = self->w04;
        p->w08 = self->w08;
        p->w0C = self->w0C;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004DB890;
        p->a24 = self->a24;
    }
    p->w0C = self->w0C;
    return p;
}