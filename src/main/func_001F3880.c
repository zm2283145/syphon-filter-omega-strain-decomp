#include "types.h"
extern void cLList_cSkaTransBLENDPtr_PushBackActual(void* s, int* v);
#pragma optimization_level 1
void* cSkaInitListOfPointers_cSkaTransBLEND_opShl(void* s, int v) { cLList_cSkaTransBLENDPtr_PushBackActual(s, &v); return s; }
#pragma optimization_level reset
