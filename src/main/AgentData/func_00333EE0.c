/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData statistics.
 */

#include "types.h"
#include "AgentData_types.h"

/* Returns statistic `stat`, or 0 when out of range. */
int cAgentData_GetStat(cAgentData* agent, unsigned char stat) {
    if (stat < AGENT_STAT_COUNT) {
        return agent->stats[stat];
    }
    return 0;
}
