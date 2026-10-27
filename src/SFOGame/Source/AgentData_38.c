/*
 * SFOGame/Source/AgentData: 2 files, 003371B0-00337490
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003371B0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "bytevec_insert.h"

extern "C" { char D_004B9320[] = "vector::insert length error\n"; }
DEFINE_BYTEVEC_INSERT(std_vector_pod_eAchievementState_insert, 0x6000000, 0x3000000, D_004B9320, D_004B9978, 0x5C, D_004B9998, 0x64, Libc_Memmove)
static inline void merge_flush_func_003371B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003371B0 */

/* merge_units: begin func_00337490 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

DEFINE_RESIZE_ELEMENT(Elem32_00337490, 32)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_tMissionStats_resize, Elem32_00337490, std_vector_imp_tMissionStats_insert, std_vector_imp_tMissionStats_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_00337490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00337490 */
