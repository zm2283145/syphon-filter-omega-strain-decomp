#include "types.h"
extern void* func_0020C280(void);
extern void func_0020C270(void* p);
/* Passes the result of func_0020C280 to func_0020C270. */
#pragma optimization_level 1
void func_0020C240(void) { func_0020C270(func_0020C280()); }
#pragma optimization_level reset
