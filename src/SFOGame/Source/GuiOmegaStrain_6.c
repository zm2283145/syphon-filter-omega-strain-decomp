/*
 * SFOGame/Source/GuiOmegaStrain: 4 files, 0034F070-0034F200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiOmegaStrain_34F070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain constructor (vtable D_004DEDE0); derives from GuiPersonnelScreen.
 */

#include "loose03_types.h"

extern char D_004DEDE0[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 8). */
GuiPersonnelScreen* GuiOmegaStrain_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DEDE0;
    self->unk64 = 8;
    return self;
}
static inline void merge_flush_GuiOmegaStrain_34F070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiOmegaStrain_34F070 */

/* merge_units: begin func_0034F0B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_34F0B0, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_0034F0B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F0B0 */

/* merge_units: begin func_0034F110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_0034F110, func_00299500, D_004AA5C8)
static inline void merge_flush_func_0034F110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F110 */

/* merge_units: begin func_0034F200 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_0034F200(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_0034F200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F200 */
