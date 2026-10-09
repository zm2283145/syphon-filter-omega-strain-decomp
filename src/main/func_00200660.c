/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int MotionGroup_CopyPair(int*, int);
extern int Motion_Lookup(int, int);
extern int func_001ADFE0(MotionSelNode*, int);

MotionSelNode* MotionSelNode_Ctor(MotionSelNode* self, int a1, int a2, int a3) {
    func_001ADFE0(self, Motion_Lookup(a2, a1));
    MotionGroup_CopyPair(&self->pair, a3);
    return self;
}
