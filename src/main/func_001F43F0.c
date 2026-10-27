#include "types.h"

extern void* cSkaAnimationSet_GetNode_cString16NR(int id);
extern void cPointer_cSkaNode_ctor_cSkaNodeP(void* self, void* motion);
extern void cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(void* dst, void* src);

/* Resolves the child's motion by id and copies its thresholds. */
void* cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(char* self, int unused, int id, void* thresholds)
{
    cPointer_cSkaNode_ctor_cSkaNodeP(self, cSkaAnimationSet_GetNode_cString16NR(id));
    cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(self + 4, thresholds);
    return self;
}
