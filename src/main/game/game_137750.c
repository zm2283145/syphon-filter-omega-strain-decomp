/*
 * main/game: range (4 files, 00137750-001378C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_node_free.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00137750 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_TREE_ROOT_DTOR(func_00137750, func_0013A320)
#pragma pop /* merge_units */
/* merge_units: end func_00137750 */

/* merge_units: begin func_001377C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_001377C0)
#pragma pop /* merge_units */
/* merge_units: end func_001377C0 */

/* merge_units: begin func_00137840 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_00137840)
#pragma pop /* merge_units */
/* merge_units: end func_00137840 */

/* merge_units: begin func_001378C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_001378C0, func_00137920)
#pragma pop /* merge_units */
/* merge_units: end func_001378C0 */
