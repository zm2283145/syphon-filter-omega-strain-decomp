/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData reset.
 */

#include "types.h"
#include "AgentData_types.h"

extern int AgentData_Reset(cAgentData* agent);

/* Full reset plus three additional flag bytes. */
int func_003361B0(cAgentData* agent) {
    int result = AgentData_Reset(agent);
    agent->unk8AC = 0;
    agent->unk8BC = 0;
    agent->unk8CC = 0;
    return result;
}
