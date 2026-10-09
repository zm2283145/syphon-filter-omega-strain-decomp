/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E00A8[];         /* Unk3D28D0 vtable */
extern int ScalarCollection_Init(L4ScalarCollection*);

Unk3D28D0* func_003D28D0(Unk3D28D0* self) {
    self->vtable = D_004E00A8;
    ScalarCollection_Init(&self->coll);
    self->unk0C = 0;
    return self;
}
