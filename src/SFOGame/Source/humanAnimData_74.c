/*
 * SFOGame/Source/humanAnimData: 1 file, 002070F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002070F0 */
#pragma push /* merge_units */
#include "types.h"
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#pragma optimization_level 1
char* cString16N_2_ctor_cStringR(char* dst, void* s)
{
    int i;
    for (i = 0; i < 31; i++) {
        char c;
        if (i < cString_Length(s))
            c = cString_opCast_constcharPtr(s)[i];
        else
            c = 0;
        dst[i] = c;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
static inline void merge_flush_func_002070F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002070F0 */
