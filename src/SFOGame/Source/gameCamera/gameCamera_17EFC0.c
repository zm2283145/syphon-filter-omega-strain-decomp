/*
 * main/gameCamera: range (3 files, 0017EFC0-0017F080)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_0017EFC0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR3(cArray_cVector_dtor, std_vector_deleter_cVector_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0017EFC0 */

/* merge_units: begin func_0017F030 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cCollisionRoutine_cBox_dtor_void_2, D_004DA330)
#pragma pop /* merge_units */
/* merge_units: end func_0017F030 */

/* merge_units: begin func_0017F080 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cCAMERA_GOBJ_dtor, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0017F080 */
