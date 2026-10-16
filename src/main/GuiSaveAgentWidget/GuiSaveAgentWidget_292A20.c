/*
 * main/GuiSaveAgentWidget: 2 files, 00292A20-00292AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00292A20 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "label_text_refresh.h"

/* Refresh a screen label text. */
extern "C" { char D_004A9D08[] = "MC_SAVETITLE"; }
DEFINE_LABEL_TEXT_REFRESH(func_00292A20, D_004A9D08)
#pragma pop /* merge_units */
/* merge_units: end func_00292A20 */

/* merge_units: begin func_00292AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004A9D18[] = "GuiTitleScreen"; }
extern "C" { char D_004A9D28[] = "titlescr"; }
DEFINE_EVENT_SOUND_CHECK(GuiAgentLoad_HandleInput, D_004A9D18, D_004A9D28)
#pragma pop /* merge_units */
/* merge_units: end func_00292AD0 */
