/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(int*, int);
extern int cSkaAnimationSet_GetNode_cString16NR(int, int);
extern int cPointer_cSkaNode_ctor_cSkaNodeP(MotionSelNode*, int);

MotionSelNode* cSkaAnimationBlend_ctor(MotionSelNode* self, int a1, int a2, int a3) {
    cPointer_cSkaNode_ctor_cSkaNodeP(self, cSkaAnimationSet_GetNode_cString16NR(a2, a1));
    cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(&self->pair, a3);
    return self;
}
