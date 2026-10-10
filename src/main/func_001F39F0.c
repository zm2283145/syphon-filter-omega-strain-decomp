#include "types.h"
extern void func_001F3A30(void* p);
/* Calls func_001F3A30 on the object and returns it. */
#pragma optimization_level 1
void* func_001F39F0(void* p) { func_001F3A30(p); return p; }
#pragma optimization_level reset
