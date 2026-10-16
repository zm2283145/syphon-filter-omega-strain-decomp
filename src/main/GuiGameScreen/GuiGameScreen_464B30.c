/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090); gui widget code.
 */

#include "loose05_types.h"

char D_004C28A8[] = "backdark"; /* child widget name */
extern Global4FFC2C* D_004FFC2C;
extern int func_0026DBC0(int value);
extern int GuiWidget_FindChildByName(void* self, char* name);
extern int func_0041EFA0(void* self);
extern int GuiWidget_Init(void* self);

int func_00464B30(GuiWidget464B30* self) {
    func_0041EFA0(self);
    self->unk4C = D_004FFC2C->unk6A0;
    return func_0026DBC0(self->unk4C);
}

/* Looks up the named child widget. */
void func_00464B70(GuiWidget464B30* self) {
    GuiWidget_Init(self);
    self->child = GuiWidget_FindChildByName(self, D_004C28A8);
}
