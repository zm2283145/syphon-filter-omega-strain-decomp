#include "types.h"
extern void std_list_cSkaBlendSequenceItemPtr_push_back(void* s);
#pragma optimization_level 1
void cLList_cSkaBlendSequenceItemPtr_PushBackActual(void* s) { std_list_cSkaBlendSequenceItemPtr_push_back(s); }
#pragma optimization_level reset
