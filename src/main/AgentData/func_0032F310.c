/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives.
 */

#include "types.h"
#include "AgentData_types.h"

extern int cAgentData_UnlockPart(cAgentData* agent, int part);

int Script_cAgentData_UnlockPart(AgentScriptArg* args) {
    int part[1];
    part[0] = args[1].i;
    cAgentData_UnlockPart(args[0].p, STACK_COPY(part));
    return 0;
}
