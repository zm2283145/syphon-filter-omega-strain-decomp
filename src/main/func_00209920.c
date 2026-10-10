#include "types.h"

extern void func_00209940(void* self);

#pragma optimization_level 1
/* Forwards to func_00209940 (unit built at -O1: no tail call). */
void func_00209920(void* self)
{
    func_00209940(self);
}
#pragma optimization_level reset
