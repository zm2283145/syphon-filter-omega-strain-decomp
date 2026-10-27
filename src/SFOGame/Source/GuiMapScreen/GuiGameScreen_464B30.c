/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090); gui widget code.
 */

#include "loose05_types.h"

char D_004C28A8[] = "backdark"; /* child widget name */
extern Global4FFC2C* g_Hud;
extern int cMap_Activate(int value);
extern int GuiWidget_FindChild_charP(void* self, char* name);
extern int GuiWidget_onWake(void* self);
extern int GuiWidget_onAdd(void* self);

int GuiMapScreen_onWake(GuiWidget464B30* self) {
    GuiWidget_onWake(self);
    self->unk4C = g_Hud->unk6A0;
    return cMap_Activate(self->unk4C);
}

/* Looks up the named child widget. */
void GuiMapScreen_onAdd(GuiWidget464B30* self) {
    GuiWidget_onAdd(self);
    self->child = GuiWidget_FindChild_charP(self, D_004C28A8);
}
