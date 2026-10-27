/*
 * main/GameGOBJ: range (2 files, 0021BE60-0021BEC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop

/* merge_units: begin func_0021BE60 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cFacingGOBJ_dtor, D_004DB3A0, cGameGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0021BE60 */

/* merge_units: begin func_0021BEC0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_RESIZE_ELEMENT(Elem16, 16)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cVector_resize, Elem16, std_vector_imp_cVector_insert, std_vector_imp_cVector_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0021BEC0 */
