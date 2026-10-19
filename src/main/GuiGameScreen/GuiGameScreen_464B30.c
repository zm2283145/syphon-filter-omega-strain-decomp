/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090); gui widget code.
 */

#include "loose05_types.h"

char D_004C28A8[] = "backdark"; /* child widget name */
extern Global4FFC2C* g_Hud;
extern int HudMap_Open(int value);
extern int GuiWidget_FindChildByName(void* self, char* name);
extern int GuiWidget_BaseWake(void* self);
extern int GuiWidget_Init(void* self);

int GuiMapScreen_Wake(GuiWidget464B30* self) {
    GuiWidget_BaseWake(self);
    self->unk4C = g_Hud->unk6A0;
    return HudMap_Open(self->unk4C);
}

/* Looks up the named child widget. */
void GuiMapScreen_Init(GuiWidget464B30* self) {
    GuiWidget_Init(self);
    self->child = GuiWidget_FindChildByName(self, D_004C28A8);
}
