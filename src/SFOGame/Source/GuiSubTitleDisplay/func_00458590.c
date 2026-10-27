#include "types.h"

typedef struct Sub10 {
    char pad[0xC];
    unsigned char active;
} Sub10;

typedef struct Obj7C {
    void* vtable;
    char pad[0x10];
    unsigned short flags;
    char pad2[0x48 - 0x16];
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    Sub10 a;
    char pad3[0x68 - 0x65];
    Sub10 b;
    char pad4[0x78 - 0x75];
    int unk78;
} Obj7C;

extern int D_004E1560;
extern void GuiWidget_ctor(Obj7C*);
extern void std_vector_cLList_TextAtomPtr_ctor(Sub10*);
extern void std_vector_float_ctor(Sub10*);

/* Constructor: base init, vtable, two sub-objects, cleared fields and flag bit 7. */
Obj7C* GuiSubTitleDisplay_ctor(Obj7C* o) {
    Sub10* b;
    Sub10* a;
    GuiWidget_ctor(o);
    a = &o->a;
    o->vtable = &D_004E1560;
    std_vector_cLList_TextAtomPtr_ctor(a);
    a->active = 1;
    b = &o->b;
    std_vector_float_ctor(b);
    b->active = 1;
    o->unk48 = 0;
    o->unk50 = 0;
    o->unk54 = 0;
    o->unk78 = 0;
    o->flags &= ~0x80;
    return o;
}
