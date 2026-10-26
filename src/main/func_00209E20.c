#include "types.h"

/* Built at a lower optimization level (keeps a real call and frame). */
#pragma optimization_level 2

extern void cSkaBlendSequenceItem_dtor(void* obj, int value);

/* Calls cSkaBlendSequenceItem_dtor(obj, -1). */
void cAllocator_cSkaBlendSequenceItem_destroy(void* self, void* obj)
{
    cSkaBlendSequenceItem_dtor(obj, -1);
}
