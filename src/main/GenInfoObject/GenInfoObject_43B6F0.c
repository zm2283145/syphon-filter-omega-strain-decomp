/*
 * main/GenInfoObject: range (2 files, 0043B6F0-0043B860)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_insert_v8.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "guarded_release.h"
#pragma pop

/* merge_units: begin func_0043B6F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TIValueIB { int a; unsigned char b; };

extern "C" {
char D_004BFD80[] = "tree::insert length error\n";
}
extern "C" {
char D_004BFDA0[] = "allocator.hh";
}
DEFINE_TREE_INSERT_V8(func_0043B6F0, TIValueIB, D_004BFD80, D_004BFDA0, 0x5C, func_0013CD40)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043B6F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043B6F0 */

/* merge_units: begin func_0043B860 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(func_0043B860)
#pragma pop /* merge_units */
/* merge_units: end func_0043B860 */
