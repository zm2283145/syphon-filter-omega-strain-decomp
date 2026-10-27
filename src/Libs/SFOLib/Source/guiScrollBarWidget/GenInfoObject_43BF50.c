#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E0F40[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiWidget_ctor(void* self);

}
struct G0043BF50 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
#define GH(off) (*(unsigned short*)((char*)p + (off)))
extern "C" G0043BF50* ConcreteWidgetClassRep_GuiScrollBarWidget_Create(void)
{
    G0043BF50* p;
    {
        AllocGuard guard;
        p = (G0043BF50*)cMemMan_Allocate(0, 0x64, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004E0F40; GB(0x54) = 0; GW(0x58) = 0; GW(0x5C) = 0; GW(0x60) = 0xA; GB(0x48) = 0; GW(0x4C) = 0; GW(0x50) = 0;
    }
    return p;
}