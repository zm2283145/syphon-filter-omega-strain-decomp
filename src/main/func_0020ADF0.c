#include "types.h"

extern void func_0020AE80(void* dst, void* src);
extern void func_0020AE60(void* dst, void* src);
extern void func_0020A5D0(void* dst, void* src);

/* Copy-assigns three members (+0, +8, +4) unless self-assignment. */
#pragma optimization_level 1
void func_0020ADF0(char* self, char* other)
{
    if (self != other) {
        func_0020AE80(self, other);
        func_0020AE60(self + 8, other + 8);
        func_0020A5D0(self + 4, other + 4);
    }
}
#pragma optimization_level reset
