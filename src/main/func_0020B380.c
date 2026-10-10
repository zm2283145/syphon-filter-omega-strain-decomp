#include "types.h"

extern void* func_0020B3C0(void* self);
extern void func_0020B3B0(void* p);

#pragma optimization_level 1
/* Passes the result of func_0020B3C0 to func_0020B3B0 (unit built at -O1). */
void func_0020B380(void* self)
{
    func_0020B3B0(func_0020B3C0(self));
}
#pragma optimization_level reset
