/*
 * Libs/SFOLib/Source/globalization: 1 file, 003FD290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin keyframe_3FD290 */
#pragma push /* merge_units */
#include "types.h"
typedef union { int i; void* p; float f; } ScriptArg;
extern int func_003FD2C0(int id);
/* Script native: returns the string for the id argument. */
int Script_GetString(ScriptArg* args)
{
    volatile int result;
    volatile int id = args[0].i;
    result = func_003FD2C0(id);
    return result;
}
static inline void merge_flush_keyframe_3FD290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end keyframe_3FD290 */
