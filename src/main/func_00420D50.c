#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
extern "C" { extern char D_004BF500[]; extern char D_004E0C00[]; void func_0041C7D0(void* self); }
struct GN457510 { void* vtable; char pad[0x10]; unsigned short flags; };
extern "C" GN457510* func_00420D50(void)
{
    GN457510* p;
    {
        AllocGuard guard;
        p = (GN457510*)Mem_Alloc(0, 0x80, D_004BF500, 0x2A);
    }
    if (p) {
        func_0041C7D0(p);
        p->vtable = D_004E0C00;
        p->flags |= 0x80;
    }
    return p;
}