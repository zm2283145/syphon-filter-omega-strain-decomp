/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ constructors.
 */

#include "gobj_types.h"

extern char D_004DF970[];   /* cVUM_GOBJ vtable */
extern cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3);
extern int func_0036D630(int* p);

cVUM_GOBJ* cVUM_GOBJ_ctor(cVUM_GOBJ* self, int* desc, int* a2) {
    cGOBJ_ctor(&self->base, desc, 1, a2);
    self->base.vtable = D_004DF970;
    self->self = self;
    self->unk70 = 0;
    func_0036D630(&self->unk74);
    self->unk1F0 = 1;
    self->unk1F1 = 1;
    self->unk1F2 = 0;
    self->unk1F3 = 0;
    self->base.unk2F = 1;
    return self;
}

/* Same as cVUM_GOBJ_ctor with a zero third constructor argument; desc is passed through. */
cVUM_GOBJ* cVUM_GOBJ_ctor2(cVUM_GOBJ* self, int* desc) {
    int zero = 0;

    cGOBJ_ctor(&self->base, desc, 1, &zero);
    self->base.vtable = D_004DF970;
    self->self = self;
    self->unk70 = 0;
    func_0036D630(&self->unk74);
    self->unk1F0 = 1;
    self->unk1F1 = 1;
    self->unk1F2 = 0;
    self->unk1F3 = 0;
    self->base.unk2F = 1;
    return self;
}
