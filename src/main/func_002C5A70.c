/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

Word* func_002C5A70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Copies a 3x3 word matrix row by row. */
Mat3Words* func_002C5A80(Mat3Words* dst, Mat3Words* src) {
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
