#include "types.h"
extern void func_001F3940(void* s);
#pragma optimization_level 1
void* func_001F3900(void* s) { func_001F3940(s); return s; }
#pragma optimization_level reset
