#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E1A20[]; extern char D_004E1940[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_004160A0(void* self);
}
struct G00466890 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
extern "C" G00466890* func_00466890(void)
{
    G00466890* p;
    {
        AllocGuard guard;
        p = (G00466890*)Mem_Alloc(0, 0x78, "guiWidget.hh", 0x2A);
    }
    if (p) {
        func_004160A0(p);
        p->vtable = D_004E1A20; p->vtable = D_004E1940; GB(0x6C) = 0; GB(0x6D) = 0; GW(0x70) = 0; GW(0x74) = 0;
    }
    return p;
}