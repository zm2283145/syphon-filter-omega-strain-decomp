/*
 * main/game: range (2 files, 00134EE0-00134FD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_00134EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
char D_0049AF00[] = "allocator.hh";
}

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00134EE0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00134EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00134EE0 */

/* merge_units: begin func_00134FD0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00134FD0)
#pragma pop /* merge_units */
/* merge_units: end func_00134FD0 */
