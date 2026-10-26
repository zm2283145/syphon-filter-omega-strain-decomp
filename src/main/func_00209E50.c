#include "types.h"

extern void cPointer_cSkaNode_opAssign(void* dst, void* src);
extern void cSkaBlendSequenceExtents_opAssign(void* dst, void* src);

/* Copy-assigns the two members (+0 and +4). */
#pragma optimization_level 1
void* cSkaBlendSequenceItem_opAssign(char* self, char* other)
{
    cPointer_cSkaNode_opAssign(self, other);
    cSkaBlendSequenceExtents_opAssign(self + 4, other + 4);
    return self;
}
#pragma optimization_level reset
