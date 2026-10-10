#include "types.h"

extern void func_00209ED0(void* dst, void* src);
extern void func_00209EB0(void* dst, void* src);

/* Copy-assigns the two members (+0 and +4). */
#pragma optimization_level 1
void* func_00209E50(char* self, char* other)
{
    func_00209ED0(self, other);
    func_00209EB0(self + 4, other + 4);
    return self;
}
#pragma optimization_level reset
