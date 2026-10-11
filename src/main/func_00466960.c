#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004C2B38[];
extern char D_004E1A20[]; extern char D_004E19B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_004160A0(void* self);
}
struct G00466960 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
extern "C" G00466960* func_00466960(void)
{
    G00466960* p;
    {
        AllocGuard guard;
        p = (G00466960*)Mem_Alloc(0, 0x70, D_004C2B38, 0x2A);
    }
    if (p) {
        func_004160A0(p);
        p->vtable = D_004E1A20; p->vtable = D_004E19B0; GW(0x6C) = 0;
    }
    return p;
}