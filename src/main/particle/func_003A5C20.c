/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "particle_types.h"

typedef struct ParticleListPos {
    void* node;
} ParticleListPos;

extern ParticleListPos* List_InsertBefore(ParticleListPos* result, void* list, ParticleListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
ParticleListPos* func_003A5C20(void* list, int* value) {
    ParticleListPos end;
    ParticleListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
