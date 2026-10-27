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
