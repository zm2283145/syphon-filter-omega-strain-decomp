#include "types.h"
#pragma optimization_level 1

extern void cLList_cSkaSwitchItemPtr_PushBackActual(void*, int*);

/* Calls cLList_cSkaSwitchItemPtr_PushBackActual(self, &value) and returns self. */
void* cSkaInitListOfPointers_cSkaSwitchItem_opShl(void* self, int value) {
    cLList_cSkaSwitchItemPtr_PushBackActual(self, &value);
    return self;
}
