/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (objective bits and statistics).
 */

#include "types.h"
#include "AgentData_types.h"

extern unsigned char AgentData_IsObjectiveComplete(cAgentData* agent, int key);
extern int AgentData_SetObjectiveBit(cAgentData* agent, int key, int global);
extern unsigned char cAgentData_AreObjectivesComplete(cAgentData* agent, int keys);

int Script_cAgentData_AreObjectivesComplete(AgentScriptArg* args) {
    int keys[1];
    keys[0] = args[1].i;
    return cAgentData_AreObjectivesComplete(args[0].p, STACK_COPY(keys));
}

int Game_IsObjectiveComplete(AgentScriptArg* args) {
    int key[1];
    key[0] = args[1].i;
    return AgentData_IsObjectiveComplete(args[0].p, STACK_COPY(key));
}

/* AgentData.AddObjective(key): sets the objective bit without the multiplayer message. */
int AgentData_AddObjective(AgentScriptArg* args) {
    int key[1];
    key[0] = args[1].i;
    AgentData_SetObjectiveBit(args[0].p, STACK_COPY(key), 0);
    return 0;
}

/* Returns statistic args[1] (0 when out of range); volatile mirrors the stack temporary. */
int Script_cAgentData_GetStat(AgentScriptArg* args) {
    unsigned char stat = args[1].u8;
    cAgentData* agent = args[0].p;
    volatile int value = stat < AGENT_STAT_COUNT ? agent->stats[stat] : 0;
    return value;
}
