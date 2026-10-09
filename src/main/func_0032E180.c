/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int Agent_GetSelected(int, int);
extern int AgentData_SetObjectiveBit(int, int, int);

int Objective_AddGlobal(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = Agent_GetSelected((int)D_004FFB50, -1);
    tmp2 = AgentData_SetObjectiveBit(tmp0, a0, 1);
    return tmp2;
}
