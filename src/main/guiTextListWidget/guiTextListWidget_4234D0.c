/*
 * main/guiTextListWidget: 3 files, 004234D0-00423540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004234D0 */
#pragma push /* merge_units */
#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiArrayWidget" yields null. */
int GuiArrayWidget_IsType(void) {
    return strcmp("GuiArrayWidget") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004234D0 */

/* merge_units: begin func_00423500 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef struct {
    char pad0[0x4C];
    int x4C;
    char pad50[0x54 - 0x50];
    int x54;
    char pad58[0x8C - 0x58];
    void* x8C;
} S;
extern void GuiScrollBarWidget_SetRange(void* a, int b, int c, int d, int e);

void GuiArrayWidget_UpdateScrollBars(S* s)
{
    if (s->x8C != 0) {
        S* t = s;
        GuiScrollBarWidget_SetRange(t->x8C, 0, t->x54, 0, t->x4C - 1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00423500 */

/* merge_units: begin func_00423540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int GuiWidget_SendEventUp(Unk423540*, int, int, int);

void GuiArrayWidget_GetFixedRow(Unk423540* self, int* out) {
    *out = self->unk84;
}

void GuiArrayWidget_SetA84(Unk423540* self, int value) {
    self->unk84 = value;
}

void GuiArrayWidget_GetFirstVisibleElement(Unk423540* self, int* outA, int* outB) {
    *outA = self->unk78;
    *outB = self->unk7C;
}

void GuiArrayWidget_SetMargin(Unk423540* self, int a, int b) {
    self->unk78 = a;
    self->unk7C = b;
}

void GuiArrayWidget_GetVisibleSize(Unk423540* self, int* outA, int* outB) {
    *outA = self->unk70;
    *outB = self->unk74;
}

void GuiArrayWidget_SetTable(Unk423540* self, int a, int b) {
    self->unk70 = a;
    self->unk74 = b;
}

int GuiArrayWidget_SendEvent21(Unk423540* self, int a, int b) {
    return GuiWidget_SendEventUp(self, 21, a, b);
}

int GuiArrayWidget_SendEvent20(Unk423540* self, int a, int b) {
    return GuiWidget_SendEventUp(self, 20, a, b);
}

void GuiArrayWidget_DrawCell(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00423540 */
