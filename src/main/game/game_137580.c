/*
 * main/game: range (2 files, 00137580-00137670)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop

/* merge_units: begin func_00137580 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_tVUMNamePairPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00137580 */

/* merge_units: begin func_00137670 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor around an out-of-line base destructor. */
DEFINE_NESTED_NULL_DTOR2(cLList_cHogFile_dtor, std_list_imp_cHogFile_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00137670 */
