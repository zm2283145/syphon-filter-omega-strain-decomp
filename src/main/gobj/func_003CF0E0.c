/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ constructor.
 */

#include "gobj_types.h"

extern char D_004DFF50[];   /* cGOBJ vtable */
extern void func_003CB090(cGOBJ* self, int* desc);

cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3) {
    func_003CB090(self, desc);
    self->vtable = D_004DFF50;
    self->unk2C = 1;
    self->unk2D = 0;
    self->unk2E = 0;
    self->unk2F = 0;
    self->unk30 = -1;
    self->unk38 = 128;
    self->unk3C = 0;
    self->unk40 = 0;
    self->darkness = 0;
    self->unk48 = 0;
    self->unk49 = a2;
    self->unk4C = *a3;
    self->unk50 = 0;
    self->unk54 = 0;
    self->attached = 0;
    self->unk5C = 0;
    self->unk10 = *desc;
    return self;
}
