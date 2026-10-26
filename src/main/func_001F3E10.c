#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* allocation);
extern "C" void cSkaBlendSequenceExtents_dtor(void* m, int flags);
extern "C" void cPointer_cSkaNode_dtor(void* m, int flags);
extern "C" void* cSkaBlendSequenceItem_dtor(void* self, short deleteFlag)
{
    if (self) {
        cSkaBlendSequenceExtents_dtor((char*)self + 4, -1);
        cPointer_cSkaNode_dtor(self, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}