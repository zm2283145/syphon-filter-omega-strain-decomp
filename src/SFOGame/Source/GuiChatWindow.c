/*
 * SFOGame/Source/GuiChatWindow: 2 files, 002AEB90-002AEC60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AEB90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004ABBA8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(ConcreteWidgetClassRep_GuiNetContacts_Create, 0x168, D_004ABBA8, GuiMissionLobbyScreen_ctor, D_004DDC20,
                           GN_W(0x84, 4); GN_W(0x160, 0); GN_W(0x164, 0))
static inline void merge_flush_func_002AEB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEB90 */

/* merge_units: begin func_002AEC60 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int start; int remain; int pad6C; int end; } Range;
extern void GuiMLTextWidget_UpdateScrollBars(Range* r);

/* Recomputes the remaining span (end - start, clamped at 0) and continues in GuiMLTextWidget_UpdateScrollBars. */
void func_002AEC60(Range* r)
{
    r->remain = r->end - r->start;
    if (r->remain < 0)
        r->remain = 0;
    GuiMLTextWidget_UpdateScrollBars(r);
}
static inline void merge_flush_func_002AEC60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEC60 */
