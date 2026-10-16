/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int Agent_GetSelected(void*, int);
extern void* D_004FFB50;
extern int D_004FFC04;
extern int GuiTitleScreen_CheckMemCard(Unk288A80*, int);
extern int func_002C9AF0(int, int);
extern int AgentData_ResetProfileNames(int);
extern int func_0041EFA0(Unk288A80*);

int GuiTitleScreen_Wake(Unk288A80* self) {
    func_0041EFA0(self);
    AgentData_ResetProfileNames(Agent_GetSelected(&D_004FFB50, -1));
    func_002C9AF0(D_004FFC04, 0);
    return GuiTitleScreen_CheckMemCard(self, 0);
}
