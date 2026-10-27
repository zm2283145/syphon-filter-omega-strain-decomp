/*
 * main/GuiMissionList: 2 files, 002ACEA0-002ACF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ACEA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Probably GuiMissionList.cc: this constructor installs the GuiMissionList vtable
 * and sits just past that unit's known address range (0x002AAC60-0x002ACCF0).
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDB80[];   /* GuiMissionList vtable */
extern Rel* std_vector_SelectElem_ctor(Rel* r);
extern GuiWidget* GuiArrayWidget_ctor(GuiWidget* self);

/* GuiMissionList constructor. */
GuiMissionListObj* GuiMissionList_ctor(GuiMissionListObj* self) {
    OwnedRel* items;

    GuiArrayWidget_ctor(&self->base);
    items = &self->items;
    self->base.vtable = D_004DDB80;
    std_vector_SelectElem_ctor(&items->vec);
    items->owned = 1;
    self->unkA8 = 0;
    self->unkAC = 1;
    self->unkAD = 1;
    self->unkB0 = 0;
    self->unkB4 = 0;
    self->unkB5 = 0;
    self->unkB8 = -1;
    self->unk58 = 2;
    self->unk11C = 0;
    self->unkBC = 0;
    self->unkCC = -1;
    self->unkC4 = -1;
    self->unkC0 = -1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002ACEA0 */

/* merge_units: begin func_002ACF30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(cArray_SelectElem_dtor, std_vector_deleter_SelectElem_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_002ACF30 */
