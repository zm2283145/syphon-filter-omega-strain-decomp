/*
 * Matched functions (byte-identical with the retail executable).
 * Indexed access into a 16-byte element table.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern char* func_00183B10(SpecTableOwner* owner, char** it);

/* Returns the address of element index of owner's table. */
char* func_00231EC0(SpecTableOwner* owner, int index) {
    char* it[1];

    it[0] = owner->table;
    return func_00183B10(owner, it) + (index << 4);
}
