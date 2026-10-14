/*
 * main/GuiGameScreen: range (2 files, 0045BEB0-0045BF10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiGameScreen_types.h"

/* merge_units: begin func_0045BEB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */


extern int func_00424430(GuiChoiceList* list, int a1, int index);

void func_0045BEB0(GuiGameScreen* self, int value) {
    self->unkEC = value;
}

/* Forwards a valid choice index (0 < index < count) to the choice list. */
void func_0045BEC0(GuiGameScreen* self, int index) {
    if (self->menu != 0 && index > 0 && index < self->choices->count) {
        func_00424430(self->choices, 0, index);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045BEB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045BEB0 */

/* merge_units: begin func_0045BF10 */
#pragma push /* merge_units */
typedef struct { char pad[0xE0]; int menuActive; void* menu; } cPlayer;

extern void func_0041BEB0(void* menu, const char* title, int flags);

/* Sets the title of the player's menu when it is active. */
void cPlayer_SetMenuTitle(cPlayer* self, const char* title)
{
    if (self->menuActive)
        func_0041BEB0(self->menu, title, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045BF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045BF10 */
