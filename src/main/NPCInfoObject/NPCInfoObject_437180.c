/*
 * main/NPCInfoObject: range (2 files, 00437180-004372F0)
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

/* merge_units: begin func_00437180 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TIValueIB { int a; unsigned char b; };

extern "C" {
char D_004BFCE0[] = "tree::insert length error\n";
}
extern "C" {
char D_004BFD00[] = "allocator.hh";
}
DEFINE_TREE_INSERT_V8(std_tree_pair_tNPCInfoPtr_value_compare_insert_node_at, TIValueIB, D_004BFCE0, D_004BFD00, 0x5C, std_red_black_tree_1_balance_insert)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00437180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00437180 */

/* merge_units: begin func_004372F0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc_17)
#pragma pop /* merge_units */
/* merge_units: end func_004372F0 */
