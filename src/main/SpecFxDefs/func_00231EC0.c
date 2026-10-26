/*
 * Matched functions (byte-identical with the retail executable).
 * Indexed access into a 16-byte element table.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(SpecTableOwner* owner, char** it);

/* Returns the address of element index of owner's table. */
char* cCollisionModel_Data_GetVertex(SpecTableOwner* owner, int index) {
    char* it[1];

    it[0] = owner->table;
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(owner, it) + (index << 4);
}
