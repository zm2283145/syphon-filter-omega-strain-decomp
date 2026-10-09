/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after guiMLTextWidget.cc (ends 0x0043E330); the vtable D_004E1040
 * points into that file, so this is probably its widget constructor.
 */

#include "loose05_types.h"

extern float D_004C0100;
extern float D_004C0104;
extern float D_004C0108;
extern float D_004C010C;
extern char D_004E1040[]; /* vtable */
extern int ScalarCollection_Init(List* list);
extern void GuiWidget_ctor(void* self);

/* Constructor: base widget, empty line list, default color. */
GuiWidget43E5D0* func_0043E5D0(GuiWidget43E5D0* self) {
    float r;
    float g;
    float b;
    float a;

    GuiWidget_ctor(self);
    self->base.vtable = D_004E1040;
    ScalarCollection_Init(&self->lines);
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk60 = 0;
    self->unk68 = 0;
    self->unk64 = 0;
    self->unk6C = 0;
    r = D_004C0100;
    self->color[0] = r;
    g = D_004C0104;
    self->color[1] = g;
    b = D_004C0108;
    self->color[2] = b;
    a = D_004C010C;
    self->color[3] = a;
    return self;
}
