/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (clearance points).
 */

#include "types.h"
#include "AgentData_types.h"

extern int AgentData_TotalPoints(cAgentData* agent);

/* Returns the agent's total clearance points; volatile mirrors the stack temporary. */
int Script_cAgentData_GetClearancePoints(AgentScriptArg* args) {
    volatile int points = AgentData_TotalPoints(args[0].p);
    return points;
}

void func_0032FD60(void) {
}
