/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

typedef struct Word {
    int value;
} Word;

/* Copy assignment: *dst = *src, returns dst. */
Word* func_00130AE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
