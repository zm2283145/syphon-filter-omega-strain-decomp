#include "types.h"
#pragma cplusplus on
struct H_60CF0 { int v; };
struct Req_60CF0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_60CF0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
    char pad187[9];
};
struct Slot_60CF0 { int a; int b; char pad[0x10]; };
struct Sub_60CF0 {
    char pad0[0x10];
    int x10;
    char pad14[0x20 - 0x14];
    char menu[0x1B0 - 0x20];
    int x1B0;
};
struct W_60CF0 {
    void* vt;
    char pad04[0x48 - 0x04];
    Slot_60CF0 slots[15];
    char pad1B0[0x1B4 - 0x1B0];
    int x1B4;
    int x1B8;
    char pad1BC[0x1C0 - 0x1BC];
    Req_60CF0 req;
    Sub_60CF0 sub;
};
extern "C" {
extern char D_004E1730[];
void GuiWidget_ctor(void* p);
void cFileMan_ctor_void(void* m);
void cArray_tQuip_ctor(Sub_60CF0* s);
void cSndFx_ctor_void(void* m);
}
#pragma opt_propagation off
#pragma opt_unroll_loops off
extern "C" W_60CF0* GuiEndGameAwards_ctor(W_60CF0* self)
{
    Req_60CF0* p;
    Sub_60CF0* s;
    int i;
    GuiWidget_ctor(self);
    p = &self->req;
    self->vt = D_004E1730;
    p->h24.v = -2;
    p->w20 = 0;
    cFileMan_ctor_void(p->memberA);
    cFileMan_ctor_void(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_60CF0 h; H_60CF0* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    s = &self->sub;
    cArray_tQuip_ctor(s);
    cSndFx_ctor_void(s->menu);
    s->x10 = 0;
    s->x1B0 = 0;
    self->x1B4 = 0;
    self->x1B8 = -1;
    i = 0;
    {
        W_60CF0* w = self;
        do {
            w->slots[0].a = 0; w->slots[0].b = 0;
            w->slots[1].a = 0; w->slots[1].b = 0;
            w->slots[2].a = 0; w->slots[2].b = 0;
            w->slots[3].a = 0; w->slots[3].b = 0;
            w->slots[4].a = 0; w->slots[4].b = 0;
            i += 5;
            w = (W_60CF0*)((char*)w + 5 * sizeof(Slot_60CF0));
        } while (i < 15);
    }
    return self;
}
