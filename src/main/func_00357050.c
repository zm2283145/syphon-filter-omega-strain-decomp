#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0x6C-byte GuiWidget-derived object and construct it inline. */
extern "C" {
extern char D_004DF0B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiWidget_ctor(void* self);
}
struct O357050 {
    void* vtable; char pad4[0x44]; int a48; int a4C; int a50; int a54; int a58;
    int a5C; int a60; int pad64; int a68;
};
extern "C" O357050* func_00357050(void)
{
    O357050* p;
    {
        AllocGuard guard;
        p = (O357050*)Mem_Alloc(0, 0x6C, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004DF0B0;
        p->a48 = 0;
        p->a4C = 0;
        p->a50 = 0;
        p->a5C = 0;
        p->a60 = 0;
        p->a54 = 0;
        p->a58 = 0;
        p->a68 = 1;
    }
    return p;
}