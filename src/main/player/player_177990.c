/*
 * main/player: range (3 files, 00177990-00177A30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00177990 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00177990)
#pragma pop /* merge_units */
/* merge_units: end func_00177990 */

/* merge_units: begin func_001779E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001779E0)
#pragma pop /* merge_units */
/* merge_units: end func_001779E0 */

/* merge_units: begin func_00177A30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00177A30, func_00177A90)
#pragma pop /* merge_units */
/* merge_units: end func_00177A30 */
