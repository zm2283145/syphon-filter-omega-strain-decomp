#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004ACF10[];
void* func_00229E60(void* p);
void func_00229C50(void* p);
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
            p = func_00229E60(p);
        o->timer = p;
        func_00229C50(o->timer);
    }
}