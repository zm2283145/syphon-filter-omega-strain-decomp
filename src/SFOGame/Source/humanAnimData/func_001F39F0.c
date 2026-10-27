#include "types.h"
extern void cLList_cSkaSwitchItemPtr_ctor(void* p);
/* Calls cLList_cSkaSwitchItemPtr_ctor on the object and returns it. */
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaSwitchItem_ctor(void* p) { cLList_cSkaSwitchItemPtr_ctor(p); return p; }
#pragma optimization_level reset
