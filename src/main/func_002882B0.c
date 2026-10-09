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
extern int func_00288310(Unk288A80*, int);
extern int func_002C9AF0(int, int);
extern int func_003361B0(int);
extern int func_0041EFA0(Unk288A80*);

int func_002882B0(Unk288A80* self) {
    func_0041EFA0(self);
    func_003361B0(Agent_GetSelected(&D_004FFB50, -1));
    func_002C9AF0(D_004FFC04, 0);
    return func_00288310(self, 0);
}
