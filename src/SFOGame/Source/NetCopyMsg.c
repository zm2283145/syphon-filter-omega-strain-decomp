/*
 * SFOGame/Source/NetCopyMsg: 1 file, 002C5A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C5A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

Word* cNpcTransfer_cStateID_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Copies a 3x3 word matrix row by row. */
Mat3Words* cBitArray_256_ctor(Mat3Words* dst, Mat3Words* src) {
    int* d;
    int* s;
    int i;

    i = 0;
    d = dst->m;
    s = src->m;
    do {
        i += 3;
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        s += 3;
        d += 3;
    } while (i < 9);
    return dst;
}
static inline void merge_flush_func_002C5A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5A70 */
