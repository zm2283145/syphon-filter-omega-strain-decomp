/*
 * main/GuiMissionStatList: 3 files, 00351070-003511D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351070 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_release_dtor.h"

extern "C" { char D_004BACC8[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(std_vector_deleter_StatsRequirement_dtor, std_vector_deleter_StatsRequirement_clear, opDelete_StatsRequirementP_int_bool_charP_etc, D_004BACC8)
#pragma pop /* merge_units */
/* merge_units: end func_00351070 */

/* merge_units: begin func_003510F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then cMemMan_Deallocate under the guard. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* cArray_StatType_dtor(void* self, short flags);
void opDelete_StatsRequirementP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_StatsRequirementP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            cArray_StatType_dtor((char*)allocation + 4, -1);
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_003510F0 */

/* merge_units: begin func_003511D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(cArray_StatType_dtor, std_vector_imp_StatType_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003511D0 */
