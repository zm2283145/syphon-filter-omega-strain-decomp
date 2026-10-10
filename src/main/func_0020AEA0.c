#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void func_0020AEC0(void* self);

/* Forwards to func_0020AEC0. */
void func_0020AEA0(void* self)
{
    func_0020AEC0(self);
}
