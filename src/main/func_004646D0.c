#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004E1840[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiScoresEquip_ctor(void* self);
void cQuipList_ctor(void* p);
}
struct G004646D0 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
#define GH(off) (*(unsigned short*)((char*)p + (off)))
extern "C" G004646D0* GuiEndGameStatistics_Create(void)
{
    G004646D0* p;
    {
        AllocGuard guard;
        p = (G004646D0*)cMemMan_Allocate(0, 0x420, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiScoresEquip_ctor(p);
        p->vtable = D_004E1840; cQuipList_ctor((char*)p + 0x260); GB(0x60) = 0;
    }
    return p;
}