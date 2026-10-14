/*
 * main/Loader: range (2 files, 001C4410-001C4480)
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
#include "guarded_buffer_dtor.h"
#pragma pop

/* merge_units: begin func_001C4410 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem1C4410, 16)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_001C4410, Elem1C4410, func_001C49F0, func_001C4890)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_001C4410 */

/* merge_units: begin func_001C4480 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
char D_0049F388[] = "allocator.hh";
}
DEFINE_GUARDED_BUFFER_CALL_DTOR(func_001C4480, func_001C4F10, D_0049F388)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4480 */
