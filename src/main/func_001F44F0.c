#include "types.h"
#pragma optimization_level 1

extern void func_001F39C0(void* self);

/* Calls func_001F39C0 on self and returns self. */
void* func_001F44F0(void* self)
{
    func_001F39C0(self);
    return self;
}
