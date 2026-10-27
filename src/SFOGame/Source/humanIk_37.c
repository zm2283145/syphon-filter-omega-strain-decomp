/*
 * SFOGame/Source/humanIk: 1 file, 001D8AE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D8AE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { Q a; Q b; char c; } QPair8AE0;
#pragma peephole off
QPair8AE0* cIkTarget_ctor(QPair8AE0* dst, QPair8AE0* src, char c)
{
    dst->a = src->a;
    dst->b = src->b;
    dst->c = c;
    return dst;
}
#pragma peephole reset
static inline void merge_flush_func_001D8AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D8AE0 */
