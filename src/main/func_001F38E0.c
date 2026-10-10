#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void func_001F3280(void* self);

/* Forwards to func_001F3280. */
void func_001F38E0(void* self)
{
    func_001F3280(self);
}
