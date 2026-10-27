#include "types.h"
extern void std_list_cSkaSwitchItemPtr_ctor(void*);
#pragma optimization_level 1
/* Calls the initializer on p and returns p. */
void* cLList_cSkaSwitchItemPtr_ctor(void* p) { std_list_cSkaSwitchItemPtr_ctor(p); return p; }
#pragma optimization_level reset
