/*
 * Matched functions (byte-identical with the retail executable).
 * Calls two helpers with the same arguments.
 */

#include "types.h"
#include "path_types.h"

extern int NpcPath_HoldAtRouteNode(void* a0, int a1);
extern void NpcPath_HoldNode(void* a0, int a1);

void NpcPath_RelocateStuck(void* a0, int a1) {
    NpcPath_HoldAtRouteNode(a0, a1);
    NpcPath_HoldNode(a0, a1);
}
