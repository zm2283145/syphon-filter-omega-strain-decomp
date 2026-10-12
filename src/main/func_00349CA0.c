#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0xA8-byte GuiScreen-derived object and construct it inline. */
extern "C" {
extern char D_004DEB10[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiScreen_ctor(void* self);
}
struct O349CA0 { void* vtable; char pad[0x80]; int a84; int a88; char pad8C[0x10]; int a9C; };
extern "C" O349CA0* func_00349CA0(void)
{
    O349CA0* p;
    {
        AllocGuard guard;
        p = (O349CA0*)Mem_Alloc(0, 0xA8, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiScreen_ctor(p);
        p->vtable = D_004DEB10;
        p->a84 = 9;
        p->a88 = 0;
        p->a9C = -1;
    }
    return p;
}