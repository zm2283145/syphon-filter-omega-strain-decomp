/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#pragma explicit_zero_data on /* the zero-initialised globals below are in .data in the original */
#include "loose02_types.h"

unsigned char D_0048B7A0 = 0;
int D_0048B7A4 = -1;
unsigned char D_0048B7A8[32] __attribute__((aligned(8))) = { 0 };
unsigned char D_0048B7C8[32] __attribute__((aligned(8))) = { 0 };
unsigned char D_0048B7E8[32] __attribute__((aligned(8))) = { 0 };
unsigned char D_0048B808[32] __attribute__((aligned(8))) = { 0 };
unsigned char D_0048B828[32] __attribute__((aligned(8))) = { 0 };
unsigned char D_0048B848[32] __attribute__((aligned(8))) = { 0 };
extern int GuiCommandCenter_OpenPanel(GuiCommandCenter* self, int arg);
extern void GuiCommandCenter_Reset(GuiCommandCenter* self);
extern int GuiCommandCenter_Select(GuiCommandCenter* self, int selection, int arg);
extern int GuiCommandCenter_GetDefaultSlot(GuiCommandCenter* self);
extern void func_00298310(void);
extern void GuiCommandCenter_RestoreSelection(GuiCommandCenter* self);

/* Refreshes the screen, picking a default selection when none is set. */
int GuiCommandCenter_RestoreState(GuiCommandCenter* self) {
    GuiCommandCenter_RestoreSelection(self);
    if (self->selection == -1) {
        GuiCommandCenter_Reset(self);
        self->selection = GuiCommandCenter_GetDefaultSlot(self);
    }
    GuiCommandCenter_Select(self, self->selection, 0);
    return GuiCommandCenter_OpenPanel(self, self->unk1D4);
}

/* Resets the selection state and the shared globals. */
void GuiCommandCenter_ClearState(GuiCommandCenter* self) {
    func_00298310();
    self->selection = -1;
    self->unk2D0 = 0;
    self->unk2D4 = 0;
    self->unk2D8 = 0;
    self->unk2DC = 0;
    self->unk2E0 = 0;
    self->unk2E4 = 0;
}

/* Clears the shared text buffers and index. */
void func_00298310(void) {
    D_0048B7A0 = 0;
    D_0048B7A8[0] = 0;
    D_0048B7A4 = -1;
    D_0048B7C8[0] = 0;
    D_0048B7E8[0] = 0;
    D_0048B808[0] = 0;
    D_0048B828[0] = 0;
    D_0048B848[0] = 0;
}
