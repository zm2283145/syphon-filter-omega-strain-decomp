#include "types.h"

extern void* Motion_Lookup(int id);
extern void func_001ADFE0(void* self, void* motion);
extern void MotionSliderChild_CopyThresholds(void* dst, void* src);

/* Resolves the child's motion by id and copies its thresholds. */
void* MotionSliderChild_Resolve(char* self, int unused, int id, void* thresholds)
{
    func_001ADFE0(self, Motion_Lookup(id));
    MotionSliderChild_CopyThresholds(self + 4, thresholds);
    return self;
}
