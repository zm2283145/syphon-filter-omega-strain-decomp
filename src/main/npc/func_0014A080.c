/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int GObj_IdentityB(int handle);
extern int cNPC_Deactivate(cNPC* npc, int player);

/* Script: cNPC.Deactivate(player). */
int Script_cNPC_Deactivate(NpcScriptArgs* args) {
    cNPC* npc;
    int player;

    npc = args->npc;
    player = GObj_IdentityB(args->arg1);
    cNPC_Deactivate(npc, player);
    return 0;
}
