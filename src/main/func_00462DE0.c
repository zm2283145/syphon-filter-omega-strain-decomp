#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E17C0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiObjectives_ctor(void* self, int a, int b);
void func_00462FA0(void* p);
}
struct O462DE0 { void* vtable; char pad4[0x8C]; char p90[0x1C0]; };
extern "C" O462DE0* func_00462DE0(void)
{
    O462DE0* p;
    {
        AllocGuard guard;
        p = (O462DE0*)Mem_Alloc(0, 0x250, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiObjectives_ctor(p, 1, 0);
        p->vtable = D_004E17C0;
        func_00462FA0(p->p90);
    }
    return p;
}