#include "types.h"

extern void func_0020BCC0(void* self);

#pragma optimization_level 1
/* Forwards to func_0020BCC0 (unit built at -O1: no tail call). */
void func_0020BCA0(void* self)
{
    func_0020BCC0(self);
}
#pragma optimization_level reset
