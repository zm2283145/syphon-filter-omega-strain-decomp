/*
 * main/GuiGameScreen: 3 files, 00460E90-00460F20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00460E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern Rel* func_00460F20(Rel* r);

/* Constructor: clears the triple and sets the enabled flag. */
FlaggedRel* func_00460E90(FlaggedRel* self) {
    func_00460F20(&self->rel);
    self->enabled = 1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00460E90 */

/* merge_units: begin func_00460EC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00460EC0, func_00461DC0)
#pragma pop /* merge_units */
/* merge_units: end func_00460EC0 */

/* merge_units: begin func_00460F20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */


Rel* func_00460F20(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00460F20 */
