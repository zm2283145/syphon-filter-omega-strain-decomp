/*
 * Libs/SFOLib/Source/guiMLTextWidget: 9 files, 0043E660-0043ED80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043E660 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_charPtr_dtor, func_00135C90)
static inline void merge_flush_func_0043E660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E660 */

/* merge_units: begin func_0043E6C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_mid.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_MID(func_0043E6C0)
static inline void merge_flush_func_0043E6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E6C0 */

/* merge_units: begin func_0043E740 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor_shallow.h"

/* Destroy an object list, optionally delete. */
DEFINE_OBJ_LIST_DTOR_SHALLOW(func_0043E740)
static inline void merge_flush_func_0043E740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E740 */

/* merge_units: begin func_0043E7B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_43E7B0)
static inline void merge_flush_func_0043E7B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E7B0 */

/* merge_units: begin func_0043E8A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_tActivatedStruct_erase)
static inline void merge_flush_func_0043E8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E8A0 */

/* merge_units: begin func_0043E9E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_one.h"

/* Erase one node from a linked list. */
DEFINE_OBJECT_LIST_ERASE_ONE(List_Erase_43E9E0)
static inline void merge_flush_func_0043E9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043E9E0 */

/* merge_units: begin func_0043EAE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(List_InsertBefore_43EAE0)
static inline void merge_flush_func_0043EAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043EAE0 */

/* merge_units: begin func_0043ECA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_0043ECA0, D_0049AE80)
static inline void merge_flush_func_0043ECA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043ECA0 */

/* merge_units: begin func_0043ED80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after guiMLTextWidget.cc (ends 0x0043E330),
 * before SFOLobby_Mission.cc (starts 0x00442510).
 */


void* func_0043ED80(char* self) {
    return self + 4;
}

List* func_0043ED90(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_0043ED80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043ED80 */
