#include "types.h"
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E327D90;
typedef struct { char p0[0x14]; unsigned short flags; } W327D90;
typedef struct {
    char p0[0x4C]; int count; E327D90* data; char p54[0x10]; W327D90* w64;
    char p68[0xD4 - 0x68]; unsigned char active;
} S327D90;
extern void* D_004FFC04;
extern char* D_00491560;
extern char* D_00491568;
extern void GuiWidget_BaseWake(S327D90* self);
extern void Heap_ReleaseSlot(int a0);
extern void Heap_AllocSlot(int a0, int a1, int a2);
extern void func_002C9AF0(void* a0, int a1);
extern void GuiSlideShow_Refresh(S327D90* self);
extern W327D90* GuiWidget_FindChildByName(S327D90* self, char* name);
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
/* Total number of sub-items over all entries (inlined func_00327F20; the
   data pointer is loaded once after the guard). */
static inline int Count327D90(S327D90* l)
{
    int total = 0;
    int i;
    int j;
    E327D90* d;
    int n;
    i = 0;
    if (0 < *(volatile int*)&l->count) {
        d = l->data;
        do {
            n = d[i].n;
            for (j = 0; j < n; j++) total++;
            i++;
        } while (i < *(volatile int*)&l->count);
    }
    return total;
}
void GuiSlideShow_Wake(S327D90* self)
{
    int n;
    W327D90* w;
    GuiWidget_BaseWake(self);
    Heap_ReleaseSlot(1);
    Heap_AllocSlot(1, 0x100000, 0x800);
    func_002C9AF0(D_004FFC04, 2);
    self->active = 0;
    GuiSlideShow_Refresh(self);
    n = Count327D90(self);
    w = self->w64;
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChildByName(self, D_00491560);
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChildByName(self, D_00491568);
    if (w) {
        if (n > 1) w->flags |= 2;
        else w->flags &= ~2;
    }
}

