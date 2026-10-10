#include "types.h"

/* Built at a lower optimization level (keeps a real call and frame). */
#pragma optimization_level 2

extern void func_001F3E10(void* obj, int value);

/* Calls func_001F3E10(obj, -1). */
void func_00209E20(void* self, void* obj)
{
    func_001F3E10(obj, -1);
}
