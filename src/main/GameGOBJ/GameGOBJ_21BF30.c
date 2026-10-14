/*
 * main/GameGOBJ: range (2 files, 0021BF30-0021BFA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_destroy_dtor.h"
#pragma pop

/* merge_units: begin func_0021BF30 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_RESIZE_ELEMENT(Elem16, 16)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_0021BF30, Elem16, func_0021C330, func_0021C260)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0021BF30 */

/* merge_units: begin func_0021BFA0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004A4A08[] = "allocator.hh";
}
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_0021BFA0, func_0021C180, D_004A4A08)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021BFA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021BFA0 */
