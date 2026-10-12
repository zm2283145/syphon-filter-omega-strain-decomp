#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E1220[]; extern char D_004E16D0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiWidget_ctor(void* self);
}
struct G00462070 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
extern "C" G00462070* func_00462070(void)
{
    G00462070* p;
    {
        AllocGuard guard;
        p = (G00462070*)Mem_Alloc(0, 0x78, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004E1220; GW(0x48) = -2; p->vtable = D_004E16D0;
    }
    return p;
}