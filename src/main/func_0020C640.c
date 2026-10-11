#include "types.h"
extern void func_001F23C0(void* p, int flags);
#pragma optimization_level 1
void func_0020C640(void* a, void* b)
{
    func_001F23C0(b, -1);
}
#pragma optimization_level reset