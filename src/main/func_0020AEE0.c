#include "types.h"

extern int* func_001F3510(void* self);

#pragma optimization_level 1
/* Returns the int pointed to by func_001F3510's result. */
int func_0020AEE0(void* self)
{
    return *func_001F3510(self);
}
#pragma optimization_level reset
