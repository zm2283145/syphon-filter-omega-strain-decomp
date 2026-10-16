/*
 * main/GuiQuickChat: 2 files, 002B1B30-002B1BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B1B30 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x4C]; int id; } Slot;
extern int sprintf(char* buf, const char* fmt, ...);
extern int GuiWidget_FindChildByName(void* self, const char* name);
extern void GuiWidget_Init(void* self);

/* Looks up four numbered children by name into the ids at +0x4C, then finishes setup. */
void GuiQuickChat_Init(void* self)
{
    char buf[0x20];
    Slot* slot;
    int i;
    for (i = 0, slot = (Slot*)self; i < 4; i++) {
        sprintf(buf, "dpad%d", i);
        slot->id = GuiWidget_FindChildByName(self, buf);
        slot = (Slot*)((int*)slot + 1);
    }
    GuiWidget_Init(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_002B1B30 */

/* merge_units: begin func_002B1BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char D_004DDE60[];   /* GuiQuickChat vtable */
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiQuickChat constructor. */
GuiQuickChat* GuiQuickChat_ctor(GuiQuickChat* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DDE60;
    self->unk48 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002B1BB0 */
