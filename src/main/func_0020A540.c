#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void func_0020A560(void* self);

/* Forwards to func_0020A560. */
void func_0020A540(void* self)
{
    func_0020A560(self);
}
