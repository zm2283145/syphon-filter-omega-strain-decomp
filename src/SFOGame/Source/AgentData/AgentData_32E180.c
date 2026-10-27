/*
 * main/AgentData: 2 files, 0032E180-0032E1C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (just before AgentData.cc).
 */

#include "loose03_types.h"

extern int cAgentData_AddObjective(int agent, int bit, int value);
extern int cGameSystem_GetAgentData(void* agents, int index);
extern char g_Game[];       /* agent list */

/* Set objective bit `bit` on the selected agent. */
int Objective_AddGlobal(int bit) {
    return cAgentData_AddObjective(cGameSystem_GetAgentData(g_Game, -1), bit, 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E180 */

/* merge_units: begin func_0032E1C0 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { char data[0x1C]; } OmegaReq;
extern char D_00532BB0[];
extern void* cAgentData_tRequirementInfo_ctor(OmegaReq* r, int a, int zero, int e, int b, int c, int d);
extern void cArray_tRequirementInfo_PushBackActual(void* registry, void* item);

/* Script native: builds an Omega requirement from args[0..4] and registers it; returns 0. */
int Script_cAgentData__RegisterOmegaReq_2(ScriptArg* args)
{
    OmegaReq r;
    int p4[1];
    int p3[1];
    int p2[1];
    int p1[1];
    int p0[1];
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    p2[0] = args[2].i;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    cArray_tRequirementInfo_PushBackActual(D_00532BB0, cAgentData_tRequirementInfo_ctor(&r, *(int*)p0, 0, *(int*)p4, *(int*)p1, *(int*)p2, *(int*)p3));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E1C0 */
