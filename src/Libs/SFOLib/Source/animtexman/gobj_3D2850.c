/*
 * main/gobj: 2 files, 003D2850-003D28D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2850 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cAnimTexturePtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003D2850 */

/* merge_units: begin func_003D28D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E00A8[];         /* Unk3D28D0 vtable */
extern int std_list_deleter_voidPtr_ctor_void(L4ScalarCollection*);

Unk3D28D0* cAnimTexMan_ctor(Unk3D28D0* self) {
    self->vtable = D_004E00A8;
    std_list_deleter_voidPtr_ctor_void(&self->coll);
    self->unk0C = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D28D0 */
