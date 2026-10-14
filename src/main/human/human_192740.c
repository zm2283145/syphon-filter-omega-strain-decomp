/*
 * main/human: range (2 files, 00192740-00192750)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00192740 */
#pragma push /* merge_units */
float func_00192740(float x, float lo, float hi) {
    float r;
    asm { max.s r, x, lo
 min.s r, r, hi }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00192740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00192740 */

/* merge_units: begin func_00192750 */
#pragma push /* merge_units */
typedef struct { float lo; float hi; unsigned char flag; } R_2750;
static inline float fmax_2750(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_2750(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float Clamp_2750(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
/* set a [lo,hi] range and clamp it into [0,1] (flag: clamp both independently) */
R_2750* func_00192750(R_2750* r, float lo, float hi, unsigned char flag)
{
    r->lo = lo;
    r->hi = hi;
    r->flag = flag;
    if (r->flag) r->hi = Clamp_2750(r->hi, 0.0f, 1.0f); else r->hi = Clamp_2750(r->hi, r->lo, 1.0f);
    if (r->flag) r->lo = Clamp_2750(r->lo, 0.0f, 1.0f); else r->lo = Clamp_2750(r->lo, 0.0f, r->hi);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00192750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00192750 */
