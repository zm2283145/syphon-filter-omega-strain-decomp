#include "types.h"

extern void func_0020A720(void* self);

#pragma optimization_level 1
/* Forwards to func_0020A720 (unit built at -O1: no tail call). */
void func_0020A700(void* self)
{
    func_0020A720(self);
}
#pragma optimization_level reset
