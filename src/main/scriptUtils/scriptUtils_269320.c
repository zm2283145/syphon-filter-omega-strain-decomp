/*
 * main/scriptUtils: range (3 files, 00269320-002693C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00269320 */
#pragma push /* merge_units */
extern int Random_Next(void);

/* Returns a random float in [lo, hi). */
float Global_Random_2(float lo, float hi) {
    float t = (float)Random_Next() / 2147483648.0f;
    float range = hi - lo;
    return lo + range * t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269320 */

/* merge_units: begin func_00269380 */
#pragma push /* merge_units */
/* Returns a random float in [0, range). */
float Global_Random(float range) { return range * ((float)Random_Next() / 2147483648.0f); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269380 */

/* merge_units: begin func_002693C0 */
#pragma push /* merge_units */
typedef union { int i; void* p; float f; } ScriptArg;
extern void Debug_PrintStub(int s);
/* Script native: prints its argument. */
int Script_Print(ScriptArg* args)
{
    volatile int s = args[0].i;
    Debug_PrintStub(s);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002693C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002693C0 */
