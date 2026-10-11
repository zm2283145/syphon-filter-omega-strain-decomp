#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern void* D_004EA0C0; extern char D_0049AEF0[]; void func_00139DF0(void* p, short f); void Mem_Free(int pool, void* p, const char* file, int line); }
extern "C" void func_00135020(void)
{
    void* p = D_004EA0C0;
    if (p) {
        {
            AllocGuard g;
            if (p) { if (p) { if (p) func_00139DF0(p, 0); } }
            Mem_Free(0, p, D_0049AEF0, 0xAF2);
        }
        D_004EA0C0 = 0;
    }
}
