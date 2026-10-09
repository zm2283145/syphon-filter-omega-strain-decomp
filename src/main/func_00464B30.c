/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090); gui widget code.
 */

#include "loose05_types.h"

extern char D_004C28A8[]; /* child widget name */
extern Global4FFC2C* D_004FFC2C;
extern int func_0026DBC0(int value);
extern int func_0041DB80(void* self, char* name);
extern int func_0041EFA0(void* self);
extern int func_0041F150(void* self);

int func_00464B30(GuiWidget464B30* self) {
    func_0041EFA0(self);
    self->unk4C = D_004FFC2C->unk6A0;
    return func_0026DBC0(self->unk4C);
}

/* Looks up the named child widget. */
void func_00464B70(GuiWidget464B30* self) {
    func_0041F150(self);
    self->child = func_0041DB80(self, D_004C28A8);
}
