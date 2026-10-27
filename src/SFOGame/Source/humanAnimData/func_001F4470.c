#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void cLList_cSkaBlendSequenceItemPtr_ctor(void* obj);

/* Runs cLList_cSkaBlendSequenceItemPtr_ctor on obj and returns obj. */
void* cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void* obj) {
    cLList_cSkaBlendSequenceItemPtr_ctor(obj);
    return obj;
}

#pragma pop
