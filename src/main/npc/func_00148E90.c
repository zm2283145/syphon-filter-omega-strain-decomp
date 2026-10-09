/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* Script: cNPC.ForceOnRadar(on). */
int Script_cNPC_ForceOnRadar(NpcScriptArgs* args) {
    args->npc->forceOnRadar = (0U < (unsigned int)args->arg1);
    return 0;
}
