/*
 * main/scriptUtils: 10 files, 00269B10-0026A270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00269B10 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_00269B10)
#pragma pop /* merge_units */
/* merge_units: end func_00269B10 */

/* merge_units: begin func_00269C00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(func_00269C00)
#pragma pop /* merge_units */
/* merge_units: end func_00269C00 */

/* merge_units: begin func_00269D40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_one.h"

/* Erase one node from a linked list. */
DEFINE_OBJECT_LIST_ERASE_ONE(func_00269D40)
#pragma pop /* merge_units */
/* merge_units: end func_00269D40 */

/* merge_units: begin func_00269E40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(func_00269E40)
#pragma pop /* merge_units */
/* merge_units: end func_00269E40 */

/* merge_units: begin func_0026A000 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_0026A000, D_0049AE80)
#pragma pop /* merge_units */
/* merge_units: end func_0026A000 */

/* merge_units: begin func_0026A0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_0026A0E0(char* self) {
    return self + 4;
}

List* func_0026A0F0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_0026A0E0 */

/* merge_units: begin func_0026A110 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_0026A110)
#pragma pop /* merge_units */
/* merge_units: end func_0026A110 */

/* merge_units: begin func_0026A190 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_0026A190)
#pragma pop /* merge_units */
/* merge_units: end func_0026A190 */

/* merge_units: begin func_0026A210 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0026A210, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_0026A210 */

/* merge_units: begin func_0026A270 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0026A270, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_0026A270 */
