#include "types.h"

extern void func_0020B310(void* self);

#pragma optimization_level 1
/* Forwards to func_0020B310 (unit built at -O1: no tail call). */
void func_0020B2F0(void* self)
{
    func_0020B310(self);
}
#pragma optimization_level reset
