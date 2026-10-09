/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int Global_ResetNpc(cNPC* npc);

/* Script: ResetNpc(npc). */
int Script_ResetNpc(NpcScriptArgs* args) {
    Global_ResetNpc(args->npc);
    return 0;
}
