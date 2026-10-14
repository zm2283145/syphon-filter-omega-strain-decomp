/*
 * main/guiWidget: 7 files, 004201A0-004209E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004201A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BF440[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(func_004201A0, D_004BF440, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_004201A0 */

/* merge_units: begin func_004204E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_004204E0)
#pragma pop /* merge_units */
/* merge_units: end func_004204E0 */

/* merge_units: begin func_004205D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(func_004205D0)
#pragma pop /* merge_units */
/* merge_units: end func_004205D0 */

/* merge_units: begin func_00420710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(func_00420710)
#pragma pop /* merge_units */
/* merge_units: end func_00420710 */

/* merge_units: begin func_004208D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_004208D0, D_0049AE80)
#pragma pop /* merge_units */
/* merge_units: end func_004208D0 */

/* merge_units: begin func_004209B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_004209B0(char* self) {
    return self + 4;
}

List* func_004209C0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_004209B0 */

/* merge_units: begin func_004209E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_004209E0)
#pragma pop /* merge_units */
/* merge_units: end func_004209E0 */
