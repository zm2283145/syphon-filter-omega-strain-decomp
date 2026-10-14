/*
 * main/GuiSubTitleDisplay: range (3 files, 00458620-00458770)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00458620 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR2(func_00458620, func_00219CC0)
#pragma pop /* merge_units */
/* merge_units: end func_00458620 */

/* merge_units: begin func_00458680 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00458680)
#pragma pop /* merge_units */
/* merge_units: end func_00458680 */

/* merge_units: begin func_00458770 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00458770, func_004587D0)
#pragma pop /* merge_units */
/* merge_units: end func_00458770 */
