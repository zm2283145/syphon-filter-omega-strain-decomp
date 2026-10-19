/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern char g_IdentityMatrix[];

void* Mtx_GetIdentity(void) {
    return g_IdentityMatrix;
}
