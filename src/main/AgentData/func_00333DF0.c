#include "types.h"
#include "AgentData_types.h"
void AgentData_ResetMission(cAgentData* agent)
{
    { int i; for (i = 0; i < 13; i++) agent->stats[i] -= agent->stats[i + 18]; }
    { int i; for (i = 18; i < 31; i++) agent->stats[i] = 0; }
    { int i; for (i = 0; i < 8; i++) agent->missionBits[i] = 0; }
}
