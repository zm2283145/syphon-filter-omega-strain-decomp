#include "types.h"

extern void func_001F3260(void* self);

#pragma optimization_level 1
/* Forwards to func_001F3260 (unit built at -O1: no tail call). */
void func_001F3240(void* self)
{
    func_001F3260(self);
}
#pragma optimization_level reset
