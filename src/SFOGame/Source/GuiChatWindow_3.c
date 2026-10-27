/*
 * SFOGame/Source/GuiChatWindow: 3 files, 002AEDE0-002AEF00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AEDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new.h"

/* Factory: allocate, run the base constructor, set the vtable. */
extern "C" { char D_004ABC50[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT(ConcreteWidgetClassRep_GuiChatWindow_Create, 0x80, D_004ABC50, GuiMLTextWidget_ctor, D_004DDCE0)
static inline void merge_flush_func_002AEDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEDE0 */

/* merge_units: begin func_002AEEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiChatWindow_dtor, D_004DDCE0, GuiMLTextWidget_dtor)
static inline void merge_flush_func_002AEEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEEA0 */

/* merge_units: begin func_002AEF00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


char D_004ABC60[] = "GuiChatWindow";   /* "GuiChatWindow" */

/* Class name getter: "GuiChatWindow". */
char* GuiChatWindow_GetClassName(void) {
    return D_004ABC60;
}
static inline void merge_flush_func_002AEF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEF00 */
