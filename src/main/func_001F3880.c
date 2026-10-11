#include "types.h"
extern void func_001F38C0(void* s, int* v);
#pragma optimization_level 1
void* func_001F3880(void* s, int v) { func_001F38C0(s, &v); return s; }
#pragma optimization_level reset
