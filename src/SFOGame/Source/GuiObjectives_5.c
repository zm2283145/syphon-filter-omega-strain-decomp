/*
 * SFOGame/Source/GuiObjectives: 1 file, 00368E80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00368E80 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0x8C-byte GuiWidget-derived object and construct it inline. */
extern "C" {
extern char D_004DF5C0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiWidget_ctor(void* self);
}
struct O368E80 {
    void* vtable; char pad4[0x54]; int a58; int a5C; char pad60[0x18];
    int a78; int a7C; int pad80; int a84; unsigned char a88; unsigned char a89;
};
extern "C" O368E80* ConcreteWidgetClassRep_GuiObjectives_Create(void)
{
    O368E80* p;
    {
        AllocGuard guard;
        p = (O368E80*)cMemMan_Allocate(0, 0x8C, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004DF5C0;
        p->a5C = -1;
        p->a58 = 0;
        p->a78 = 0;
        p->a7C = 0;
        p->a84 = 0;
        p->a88 = 1;
        p->a89 = 1;
    }
    return p;
}
static inline void merge_flush_func_00368E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00368E80 */
