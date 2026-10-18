/*
 * main/GuiCharacterDisplay: 3 files, 003267D0-00326810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003267D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004B8660[] = "GuiCharacterDisplay";   /* "GuiCharacterDisplay" */

/* Class name getter: "GuiCharacterDisplay". */
char* GuiCharacterDisplay_GetClassName(void) {
    return D_004B8660;
}
#pragma pop /* merge_units */
/* merge_units: end func_003267D0 */

/* merge_units: begin func_003267E0 */
#pragma push /* merge_units */
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int GuiCharacterDisplay_IsType(void* a0, const char* s) { return strcmp("GuiCharacterDisplay", s) == 0; }
#pragma pop /* merge_units */
/* merge_units: end func_003267E0 */

/* merge_units: begin func_00326810 */
#pragma push /* merge_units */
#include "loose02_types.h"

extern char D_004DE670[];   /* GuiCharacterDisplay vtable */
extern int GuiWidget_Draw(GuiWidget* self);
extern int GuiWidget_BaseWake(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiCharacterDisplay vtable slot 10: base call, then the optional callback. */
void GuiCharacterDisplay_Draw(GuiCharacterDisplay* self) {
    GuiWidget_Draw(&self->base);
    if (self->onDestroy != 0) {
        self->onDestroy();
    }
}

/* GuiCharacterDisplay vtable slot 5: forwards to the base widget. */
int func_00326850(GuiWidget* self) {
    return GuiWidget_BaseWake(self);
}

/* GuiCharacterDisplay constructor. */
GuiCharacterDisplay* GuiCharacterDisplay_ctor(GuiCharacterDisplay* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DE670;
    self->onDestroy = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00326810 */
