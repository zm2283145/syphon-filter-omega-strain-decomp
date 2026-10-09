/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern void cNPC_SetSkill(cNPC* npc, float skill);

/* Script: cNPC.SetSkill(skill); the argument word holds a float. */
int Script_cNPC_SetSkill(NpcScriptArgs* args) {
    NpcScriptWord skill;

    skill.i = args->arg1;
    cNPC_SetSkill(args->npc, skill.f);
    return 0;
}
