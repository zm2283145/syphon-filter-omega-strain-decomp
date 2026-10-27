/*
 * Script_cAgentData_HasRank: true when the highest rank reachable with the
 * agent's total points has the given name.
 */
#include "types.h"
#include "AgentData_types.h"

/* Rank registry row (0x24 bytes). */
typedef struct RankRow {
    char* name;
    int unk04;
    int points;
    char pad0C[0x24 - 0xC];
} RankRow;

/* Rank registry vector (PtrVec layout). */
typedef struct RankVec {
    int unk0;
    int count;
    RankRow* data;
} RankVec;

extern RankVec g_RankRows;
extern int cAgentData_GetClearancePoints(cAgentData* agent);
extern int strcmp(const char*, const char*);

static inline unsigned char HasRank(cAgentData* agent, char* name) {
    int pts;
    int best;
    int bestPts;
    int i;
    pts = cAgentData_GetClearancePoints(agent);
    best = -1;
    bestPts = 0;
    for (i = 0; i < g_RankRows.count; i++) {
        if (pts >= g_RankRows.data[i].points && g_RankRows.data[i].points >= bestPts) {
            bestPts = g_RankRows.data[i].points;
            best = i;
        }
    }
    if (best > -1 && strcmp(g_RankRows.data[best].name, name) == 0)
        return 1;
    return 0;
}

#pragma opt_strength_reduction off
int Script_cAgentData_HasRank(AgentScriptArg* args) {
    cAgentData* agent = args[0].p;
    int name[1];
    name[0] = args[1].i;
    return HasRank(agent, (char*)STACK_COPY(name));
}
