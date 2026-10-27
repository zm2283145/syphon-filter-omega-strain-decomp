/*
 * Libs/SFOLib/Source/particle: 1 file, 003A5C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A5C20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "particle_types.h"

typedef struct ParticleListPos {
    void* node;
} ParticleListPos;

extern ParticleListPos* std_list_deleter_voidPtr_insert(ParticleListPos* result, void* list, ParticleListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
ParticleListPos* std_list_cParticleDefinitionPtr_push_back(void* list, int* value) {
    ParticleListPos end;
    ParticleListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_003A5C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A5C20 */
