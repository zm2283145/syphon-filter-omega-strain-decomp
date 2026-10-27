/*
 * CW_PS2Support/gcc_wrapper: 2 files, 00100230-001002D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00100230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Soft-float double comparison wrappers around SoftFloat_UnpackAndCompare
 * (result < 0, 0 or > 0).
 */

#include "types.h"

extern int SoftFloat_UnpackAndCompare(int a, int b);

/* a >= b */
int _dpfge(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return ((cmp < 0) ^ 1);
}

/* a > b */
int _dpfgt(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return (0 < cmp);
}

/* a <= b */
int _dpfle(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return ((0 < cmp) ^ 1);
}

/* a != b */
int _dpfne(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return cmp != 0;
}
static inline void merge_flush_func_00100230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00100230 */

/* merge_units: begin func_001002D0 */
#pragma push /* merge_units */
extern float SoftFloat_S64ToFloat(long long);
float _f_ulltof(unsigned long long x) {
    float f;
    if ((long long)x > 0) return SoftFloat_S64ToFloat(x);
    f = SoftFloat_S64ToFloat((x >> 1) | (x & 1));
    return f + f;
}
static inline void merge_flush_func_001002D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001002D0 */
