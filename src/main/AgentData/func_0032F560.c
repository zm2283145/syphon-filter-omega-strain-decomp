/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (unlocks, objective queries, bonus levels).
 */

#include "types.h"
#include "AgentData_types.h"

extern unsigned char AgentData_IsObjectiveComplete(cAgentData* agent, int key);
extern int D_0049D010;
extern AgentGObj* GObj_IdentityB(int handle);
extern unsigned char Global_IsObjectiveComplete(AgentGObj* gobj, int key);
extern unsigned char cAgentData_HasBonusLevel(cAgentData* agent, int level);
extern void cAgentData_UnlockLevel(cAgentData* agent, int level);
extern void cAgentData_UnlockWeapon(cAgentData* agent, int weapon);
extern cAgentData* func_00185C70(AgentGObj* gobj);

int Script_cAgentData_UnlockWeapon(AgentScriptArg* args) {
    int weapon[1];
    weapon[0] = args[1].i;
    cAgentData_UnlockWeapon(args[0].p, STACK_COPY(weapon));
    return 0;
}

int Script_cAgentData_UnlockLevel(AgentScriptArg* args) {
    int level[1];
    level[0] = args[1].i;
    cAgentData_UnlockLevel(args[0].p, STACK_COPY(level));
    return 0;
}

/* game::IsObjectiveComplete(gobj, key); the volatile local mirrors the stack temporary. */
int Script_IsObjectiveComplete(AgentScriptArg* args) {
    volatile int key = args[1].i;
    AgentGObj* gobj = GObj_IdentityB(args[0].i);
    return Global_IsObjectiveComplete(gobj, key);
}

/* Queries the agent data of an object of the agent class; other objects report false. */
unsigned char Global_IsObjectiveComplete(AgentGObj* gobj, int key) {
    if (gobj->classKey == D_0049D010) {
        return AgentData_IsObjectiveComplete(func_00185C70(gobj), key);
    }
    return 0;
}

int Script_cAgentData_HasBonusLevel(AgentScriptArg* args) {
    int level[1];
    level[0] = args[1].i;
    return cAgentData_HasBonusLevel(args[0].p, STACK_COPY(level));
}
