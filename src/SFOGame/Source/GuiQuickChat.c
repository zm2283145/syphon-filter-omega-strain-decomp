/*
 * SFOGame/Source/GuiQuickChat: 3 files, 002B0E80-002B0EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B0E80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004ABF40[] = "GuiQuickChat";   /* "GuiQuickChat" */

/* Class name getter: "GuiQuickChat". */
char* GuiQuickChat_GetClassName(void) {
    return D_004ABF40;
}
static inline void merge_flush_func_002B0E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0E80 */

/* merge_units: begin func_002B0E90 */
#pragma push /* merge_units */
extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiQuickChat" yields null. */
int GuiQuickChat_IsClass(void) {
    return strcmp("GuiQuickChat") == 0;
}
static inline void merge_flush_func_002B0E90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0E90 */

/* merge_units: begin func_002B0EC0 */
#pragma push /* merge_units */
#include "loose02_types.h"

extern void* cGOBJ_SOBJ_convert(void* obj);
extern int Global_SetLocation(void* obj, int location);

/* Script native: SetLocation(object, location). */
int Script_SetLocation(ScriptArg* args) {
    int loc[1];

    loc[0] = args[1].i;
    Global_SetLocation(cGOBJ_SOBJ_convert(args[0].p), STACK_COPY(loc));
    return 0;
}
static inline void merge_flush_func_002B0EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0EC0 */
