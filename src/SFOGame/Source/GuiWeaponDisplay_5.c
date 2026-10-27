/*
 * SFOGame/Source/GuiWeaponDisplay: 1 file, 00441180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00441180 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};

extern "C" char D_004C03A0[];
static void * const dat_004976C8[2] = { (void*)D_004C03A0, (void*)0x0 };
extern char D_004A7520[];
extern "C" void GuiWidget_onAdd(void* self);
extern "C" Widget* GuiWidget_FindChild_charP(void* self, int id);
typedef struct Screen { char pad[0xA0]; Widget* child; /* +0xA0 */ } Screen;

/* GuiWidget_onAdd, then caches the (*(int*)dat_004976C8) child at +0xA0 if it is of type D_004A7520 (virtual +0x58), else 0. */
extern "C" void GuiWeaponDisplay_onAdd(Screen* self)
{
    Widget* child;
    GuiWidget_onAdd(self);
    child = GuiWidget_FindChild_charP(self, (*(int*)dat_004976C8));
    if (!child || !child->IsA(D_004A7520))
    child = 0;
    self->child = child;
}
static inline void merge_flush_func_00441180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00441180 */
