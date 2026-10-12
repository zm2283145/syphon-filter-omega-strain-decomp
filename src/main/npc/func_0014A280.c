/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int GObj_IdentityB(int handle);
extern int NpcAi_ActivateForPlayer(cNPC* npc, int player);

/* Script: cNPC.Activate(player). */
int Script_cNPC_Activate(NpcScriptArgs* args) {
    cNPC* npc;
    int player;

    npc = args->npc;
    player = GObj_IdentityB(args->arg1);
    NpcAi_ActivateForPlayer(npc, player);
    return 0;
}

/* Script: cNPC.ActivateAnon(). */
int Script_cNPC_ActivateAnon(NpcScriptArgs* args) {
    NpcAi_ActivateForPlayer(args->npc, 0);
    return 0;
}
