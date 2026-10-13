#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004ACF10[];
void* FrontEndScene_ctor(void* p);
void FrontEndScene_Init(void* p);
}
struct Obj9D50 { char pad[0x260]; void* timer; };
extern "C" void func_002C9D50(Obj9D50* o)
{
    if (!o->timer) {
        void* p;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, 0x3C, D_004ACF10, 0x645);
        }
        if (p)
            p = FrontEndScene_ctor(p);
        o->timer = p;
        FrontEndScene_Init(o->timer);
    }
}