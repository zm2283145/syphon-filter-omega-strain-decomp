/*
 * Libs/SFOLib/Source/guiMLTextWidget: 1 file, 0043E5D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiMLTextWidget_43E5D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after guiMLTextWidget.cc (ends 0x0043E330); the vtable D_004E1040
 * points into that file, so this is probably its widget constructor.
 */

#include "loose05_types.h"

extern float D_004C0100;
unsigned int D_004C0104[1] = { 0x0 };
unsigned int D_004C0108[1] = { 0x0 };
unsigned int D_004C010C[1] = { 0x0 };
extern char D_004E1040[]; /* vtable */
extern int std_list_deleter_voidPtr_ctor_void(List* list);
extern void GuiWidget_ctor(void* self);

/* Constructor: base widget, empty line list, default color. */
GuiWidget43E5D0* GuiMLTextWidget_ctor(GuiWidget43E5D0* self) {
    float r;
    float g;
    float b;
    float a;

    GuiWidget_ctor(self);
    self->base.vtable = D_004E1040;
    std_list_deleter_voidPtr_ctor_void(&self->lines);
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk60 = 0;
    self->unk68 = 0;
    self->unk64 = 0;
    self->unk6C = 0;
    r = D_004C0100;
    self->color[0] = r;
    g = (*(float*)D_004C0104);
    self->color[1] = g;
    b = (*(float*)D_004C0108);
    self->color[2] = b;
    a = (*(float*)D_004C010C);
    self->color[3] = a;
    return self;
}
static inline void merge_flush_guiMLTextWidget_43E5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiMLTextWidget_43E5D0 */
