#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

extern void func_001F39C0(void* self);

/* Runs func_001F39C0 on self and returns self. */
void* func_001F3A70(void* self)
{
    func_001F39C0(self);
    return self;
}
