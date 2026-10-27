/*
 * SFOGame/Source/GuiZeusShell: 2 files, 002B0C50-002B0D10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B0C50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004ABE50[] = "GuiCommandCenter"; }
extern "C" { char D_004ABE68[] = "cmdcentr"; }
DEFINE_EVENT_SOUND_CHECK(GuiZeusShell_onInput, D_004ABE50, D_004ABE68)
static inline void merge_flush_func_002B0C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0C50 */

/* merge_units: begin GuiZeusShell_2B0D10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char D_004DDDE0[];   /* GuiZeusShell vtable */
extern int GuiWidget_onWake(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiZeusShell vtable slot 5: forwards to the base widget. */
int GuiZeusShell_onWake(GuiWidget* self) {
    return GuiWidget_onWake(self);
}

/* GuiZeusShell constructor. */
GuiWidget* GuiZeusShell_ctor(GuiWidget* self) {
    GuiWidget_ctor(self);
    self->vtable = D_004DDDE0;
    return self;
}
static inline void merge_flush_GuiZeusShell_2B0D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiZeusShell_2B0D10 */
