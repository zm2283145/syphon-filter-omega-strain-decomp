/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int GObj_IdentityB(int handle);
extern int func_00157800(cNPC* npc, int player);

/* Script: cNPC.Activate(player). */
int Script_cNPC_Activate(NpcScriptArgs* args) {
    cNPC* npc;
    int player;

    npc = args->npc;
    player = GObj_IdentityB(args->arg1);
    func_00157800(npc, player);
    return 0;
}

/* Script: cNPC.ActivateAnon(). */
int Script_cNPC_ActivateAnon(NpcScriptArgs* args) {
    func_00157800(args->npc, 0);
    return 0;
}
