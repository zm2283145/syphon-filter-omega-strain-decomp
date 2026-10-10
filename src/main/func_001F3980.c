#include "types.h"

extern void func_001F39C0(void* self);

#pragma optimization_level 1
/* Calls func_001F39C0 on self and returns self (unit built at -O1). */
void* func_001F3980(void* self)
{
    func_001F39C0(self);
    return self;
}
#pragma optimization_level reset
