#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
extern "C" {
extern char D_004E0C00[];
void GuiTextWidget_ctor(void* self);
}
struct GN457510 { void* vtable; char pad[0x10]; unsigned short flags; };
extern "C" GN457510* GuiButtonWidget_ctor(void)
{
    GN457510* p;
    {
        AllocGuard guard;
        p = (GN457510*)Mem_Alloc(0, 0x80, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiTextWidget_ctor(p);
        p->vtable = D_004E0C00;
        p->flags |= 0x80;
    }
    return p;
}