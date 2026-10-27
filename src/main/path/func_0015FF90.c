/*
 * Matched functions (byte-identical with the retail executable).
 * Calls two helpers with the same arguments.
 */

#include "types.h"
#include "path_types.h"

extern int cPathNavigator_ResolvePathAfterTeleport(void* a0, int a1);
extern void cPathNavigator_SetNodeIndex(void* a0, int a1);

void cPathNavigator_AdjustPathForTeleport(void* a0, int a1) {
    cPathNavigator_ResolvePathAfterTeleport(a0, a1);
    cPathNavigator_SetNodeIndex(a0, a1);
}
