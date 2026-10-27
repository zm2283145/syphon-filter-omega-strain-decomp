/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (medals).
 */

#include "types.h"
#include "AgentData_types.h"

extern unsigned char cAgentData_HasMedal(cAgentData* agent, int medal);

int Script_cAgentData_HasMedal(AgentScriptArg* args) {
    int medal[1];
    medal[0] = args[1].i;
    return cAgentData_HasMedal(args[0].p, STACK_COPY(medal));
}
