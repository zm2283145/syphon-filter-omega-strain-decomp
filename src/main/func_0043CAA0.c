/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between GenInfoObject.cc and guiMLTextWidget.cc; gui widget code.
 */

#include "loose05_types.h"

extern char D_004E0FC0[]; /* vtable */
extern int D_00539248;    /* resource registry */
extern int func_003813A0(int registry, int handle, int arg);
extern int func_0041EBF0(void* self);
extern int func_0041EFA0(void* self);
extern void GuiWidget_ctor(void* self);
extern int func_0043C730(GuiWidget43CB20* self);

/* Shutdown: base shutdown, then releases the held registry handle. */
void func_0043CAA0(GuiWidget43CB20* self) {
    func_0041EBF0(self);
    if (self->handle != -1) {
        func_003813A0(D_00539248, self->handle, 0);
        self->handle = -1;
    }
}

int func_0043CAF0(GuiWidget43CB20* self) {
    func_0041EFA0(self);
    return func_0043C730(self);
}

/* Constructor: no handle, white color. */
GuiWidget43CB20* func_0043CB20(GuiWidget43CB20* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004E0FC0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->handle = -1;
    self->unk4C = 0;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    self->unk70 = 1.0f;
    return self;
}
