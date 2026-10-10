#include "types.h"

/* Built at a lower optimization level (keeps a real call and frame). */
#pragma optimization_level 2

extern int* func_0020BF00(void* self);

/* Returns the word pointed to by func_0020BF00(self). */
int func_0020BF10(void* self)
{
    return *func_0020BF00(self);
}
