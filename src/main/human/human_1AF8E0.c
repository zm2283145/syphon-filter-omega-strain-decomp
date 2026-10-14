/*
 * main/human: range (2 files, 001AF8E0-001AF9D0)
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
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_001AF8E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_001AF8E0)
#pragma pop /* merge_units */
/* merge_units: end func_001AF8E0 */

/* merge_units: begin func_001AF9D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_001AF9D0, func_001AFA30)
#pragma pop /* merge_units */
/* merge_units: end func_001AF9D0 */
