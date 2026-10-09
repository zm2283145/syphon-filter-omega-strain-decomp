/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

/* Copies a four-float vector. */
SubVec4* func_00412150(SubVec4* dst, SubVec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}

char* func_00412180(SubtitleBlock* b) {
    return b->unk50;
}

/* Address of column col in the current row (rows of 320 bytes, columns of 100 bytes). */
int func_00412190(SubtitleBlock* b, int col) {
    int row = b->unk68;
    int base = b->base;
    return (base + (row * 320)) + (col * 100);
}
