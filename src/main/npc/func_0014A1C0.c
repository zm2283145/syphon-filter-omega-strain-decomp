/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int GObj_IdentityB(int handle);
extern int func_0016DDB0(NpcAi* ai, int target, int priority);

/* Script: cNPC.ResumeAITargeting(). */
int Script_cNPC_ResumeAITargeting(NpcScriptArgs* args) {
    args->npc->ai->targetOverride = 0;
    return 0;
}

/* Script: cNPC.ClearTarget(). */
int Script_cNPC_ClearTarget(NpcScriptArgs* args) {
    func_0016DDB0(args->npc->ai, 0, 100);
    return 0;
}

/* Script: cNPC.SetTarget(gobj). */
int Script_cNPC_SetTarget(NpcScriptArgs* args) {
    int target;

    target = GObj_IdentityB(args->arg1);
    func_0016DDB0(args->npc->ai, target, 100);
    return 0;
}
