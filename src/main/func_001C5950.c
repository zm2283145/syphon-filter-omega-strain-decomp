/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern char D_004DAA10[]; /* vtable of the derived object */
extern char D_004DF860[]; /* vtable of its intermediate base */
extern cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3);

/* Constructor of a cGOBJ-derived object (two inlined constructor levels). */
UnkGobj001C5950* func_001C5950(UnkGobj001C5950* self, int* desc, int value) {
    int zero[1];

    zero[0] = 0;
    cGOBJ_ctor(&self->base, desc, 4, zero);
    self->base.vtable = D_004DF860;
    self->unk60 = value;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk70 = 1.0f;
    self->base.unk2F = 1;
    self->base.vtable = D_004DAA10;
    return self;
}
