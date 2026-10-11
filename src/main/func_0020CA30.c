#include "types.h"
extern void func_00136DA0(void* g);
extern void func_0012F530(void* g, int flags);
extern void func_001F2800(void* p, int flags);
extern void Mem_Free(void* a, void* b, void* c, int d);
#pragma optimization_level 1
void func_0020CA30(void* p, void* pool, int destroy, void* file, int line)
{
    int g[1];
    func_00136DA0(g);
    if (destroy)
        func_001F2800(p, -1);
    Mem_Free(pool, p, file, line);
    func_0012F530(g, -1);
}
#pragma optimization_level reset