#include "types.h"
extern void func_001F3A70(void*);
#pragma optimization_level 1
/* Calls the initializer on p and returns p. */
void* func_001F3A30(void* p) { func_001F3A70(p); return p; }
#pragma optimization_level reset
