#include "types.h"
extern void cLList_cSkaTransBLENDPtr_ctor(void* s);
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_ctor(void* s) { cLList_cSkaTransBLENDPtr_ctor(s); return s; }
#pragma optimization_level reset
