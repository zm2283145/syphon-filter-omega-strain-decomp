/*
 * main/scriptUtils: range (2 files, 00269250-002692D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00269250 */
#pragma push /* merge_units */
extern int Random_Next(void);
float Global_RandomInt(float lo, float hi)
{
    float r = (float)Random_Next() / 2147483648.0f;
    float d = (float)((int)hi - (int)lo);
    return (float)(int)((float)(int)lo + d * r);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269250 */

/* merge_units: begin func_002692D0 */
#pragma push /* merge_units */
float Script_RandomIntCore(float max)
{
    return (float)(int)((float)(int)max * ((float)Random_Next() / 2147483648.0f));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002692D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002692D0 */
