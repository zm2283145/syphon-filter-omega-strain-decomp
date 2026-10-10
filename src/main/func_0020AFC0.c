#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

extern void func_0020B000(void* self);

/* Runs func_0020B000 on self and returns self. */
void* func_0020AFC0(void* self)
{
    func_0020B000(self);
    return self;
}
