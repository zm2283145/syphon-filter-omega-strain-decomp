/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (just before AgentData.cc).
 */

#include "loose03_types.h"

extern int AgentData_SetObjectiveBit(int agent, int bit, int value);
extern int Agent_GetSelected(void* agents, int index);
extern char D_004FFB50[];       /* agent list */

/* Set objective bit `bit` on the selected agent. */
int Objective_AddGlobal(int bit) {
    return AgentData_SetObjectiveBit(Agent_GetSelected(D_004FFB50, -1), bit, 1);
}
