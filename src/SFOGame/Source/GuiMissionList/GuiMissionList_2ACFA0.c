/*
 * main/GuiMissionList: 3 files, 002ACFA0-002AD080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ACFA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "nested_null_dtor.h"

/* Deleting destructor around an out-of-line base destructor. */
DEFINE_NESTED_NULL_DTOR2(std_vector_SelectElem_dtor, std_vector_deleter_SelectElem_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_002ACFA0 */

/* merge_units: begin func_002AD000 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_member_base_dtor.h"

/* Derived destructor: member, then base, optionally delete. */
DEFINE_VTABLE_MEMBER_BASE_DTOR(GuiArrayWidget_dtor, D_004E0D20, 0x60, func_0013A040, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002AD000 */

/* merge_units: begin func_002AD080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_SelectElem_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_002AD080 */
