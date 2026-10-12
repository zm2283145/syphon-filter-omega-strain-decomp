#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E1840[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_0035D430(void* self);
void func_00462FA0(void* p);
}
struct G004646D0 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
#define GH(off) (*(unsigned short*)((char*)p + (off)))
extern "C" G004646D0* func_004646D0(void)
{
    G004646D0* p;
    {
        AllocGuard guard;
        p = (G004646D0*)Mem_Alloc(0, 0x420, "guiWidget.hh", 0x2A);
    }
    if (p) {
        func_0035D430(p);
        p->vtable = D_004E1840; func_00462FA0((char*)p + 0x260); GB(0x60) = 0;
    }
    return p;
}