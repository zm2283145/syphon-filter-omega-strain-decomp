#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void cLList_cSkaBlendSequenceItemPtr_PushBackActual(void* obj, int* value);

/* Passes value by reference to cLList_cSkaBlendSequenceItemPtr_PushBackActual; returns obj. */
void* cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(void* obj, int value) {
    cLList_cSkaBlendSequenceItemPtr_PushBackActual(obj, &value);
    return obj;
}

#pragma pop
