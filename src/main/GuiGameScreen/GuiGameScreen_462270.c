/*
 * main/GuiGameScreen: 2 files, 00462270-00462340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00462270 */
#pragma push /* merge_units */
#include "types.h"
#include "fam5_timed_retry.h"
extern void GuiObjectives_onAdvanceTime(char*, float);
DEFINE_TIMED_RETRY(GuiEndGameObjectives_onAdvanceTime, 0x240, 0x90, GuiObjectives_onAdvanceTime)
#pragma pop /* merge_units */
/* merge_units: end func_00462270 */

/* merge_units: begin func_00462340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */



char* GuiEndGameObjectives_GetClassName(void) {
    return "GuiEndGameObjectives";
}
#pragma pop /* merge_units */
/* merge_units: end func_00462340 */
