#include "types.h"

extern void* Motion_Lookup(int id);
extern void cPointer_cSkaNode_ctor_cSkaNodeP(void* self, void* motion);
extern void MotionSliderChild_CopyThresholds(void* dst, void* src);

/* Resolves the child's motion by id and copies its thresholds. */
void* MotionSliderChild_Resolve(char* self, int unused, int id, void* thresholds)
{
    cPointer_cSkaNode_ctor_cSkaNodeP(self, Motion_Lookup(id));
    MotionSliderChild_CopyThresholds(self + 4, thresholds);
    return self;
}
