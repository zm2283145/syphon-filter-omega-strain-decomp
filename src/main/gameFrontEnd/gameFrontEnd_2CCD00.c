/*
 * main/gameFrontEnd: range (2 files, 002CCD00-002CCD80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_002CCD00 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_GuiWidgetPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002CCD00 */

/* merge_units: begin func_002CCD80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_GuiWidgetPtr_dtor, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_002CCD80 */
