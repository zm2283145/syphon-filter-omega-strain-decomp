/*
 * Libs/SFOLib/Source/specfx: 1 file, 003EC2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC2A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Global special-effect list registration.
 */

#include "types.h"
#include "specfx_types.h"

extern char D_0055C0A8[];   /* global effect list */
extern SpecFxListPos* std_list_deleter_voidPtr_insert(SpecFxListPos* result, void* list, SpecFxListPos* pos, int* value);
extern SpecFxListPos* std_list_cSfxSchedulerPtr_push_back(void* list, int* value);

/* Appends fx to the global effect list. */
void nDynamicSfxList_Add(SpecFx* fx) {
    int value[1];

    value[0] = (int)fx;
    std_list_cSfxSchedulerPtr_push_back(D_0055C0A8, value);
}

/* push_back on a list whose sentinel node is at +4. */
SpecFxListPos* std_list_cSfxSchedulerPtr_push_back(void* list, int* value) {
    SpecFxListPos end;
    SpecFxListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_003EC2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC2A0 */
