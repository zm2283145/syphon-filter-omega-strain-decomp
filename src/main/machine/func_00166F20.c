#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void Mem_Free(int pool, void* p, char* file, int line); extern char D_0049C390[]; void func_0027B690(void* p, int flags); }
struct O_166F20 { char pad[0x27C]; void* m; };
extern "C" void func_00166F20(O_166F20* self)
{
    void* m = self->m;
    if (m) {
        {
            AllocGuard g;
            func_0027B690(m, -1);
            Mem_Free(0, m, D_0049C390, 0x607);
        }
        self->m = 0;
    }
}