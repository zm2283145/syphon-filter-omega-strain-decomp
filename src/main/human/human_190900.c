/*
 * main/human: range (3 files, 00190900-00190940)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00190900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_00190900(char* self) {
    return self + 64;
}

int RootClip_IsEnabled(G18* s) {
    return s->v != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190900 */

/* merge_units: begin func_00190920 */
#pragma push /* merge_units */
typedef struct FlagObj {
    char pad00[0x20];
    int flags; /* 0x20 */
} FlagObj;

/* Returns whether bit `bit` is set in the object's flag word. */
int func_00190920(FlagObj* obj, int bit) {
    return (obj->flags & (1 << bit)) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190920 */

/* merge_units: begin func_00190940 */
#pragma push /* merge_units */
void* func_00190940(char* self) {
    return self + 16;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190940 */
