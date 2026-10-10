#include "types.h"

extern char D_004FFB50[];
extern void* Agent_GetSelected(void* registry, int agent);
extern int cAgentData_GetStat(void* data, int stat);

/* Returns stat `part` as a percentage of stat `total` for the agent (0 when total is 0). */
int Agent_GetStatPercent(int agent, int part, int total) {
    void* data = Agent_GetSelected(D_004FFB50, agent);
    int percent = 0;
    int totalValue = cAgentData_GetStat(data, total);
    int partValue = cAgentData_GetStat(data, part);
    if (totalValue) {
        percent = partValue * 100 / totalValue;
    }
    return percent;
}
