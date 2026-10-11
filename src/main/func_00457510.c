#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
extern "C" { extern char D_004C1CA0[]; extern char D_004E1490[]; void GuiWidget_ctor(void* self); }
struct GN457510 { void* vtable; char pad[0x10]; unsigned short flags; };
extern "C" GN457510* func_00457510(void)
{
    GN457510* p;
    {
        AllocGuard guard;
        p = (GN457510*)Mem_Alloc(0, 0x48, D_004C1CA0, 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004E1490;
        p->flags &= ~0x20;
    }
    return p;
}