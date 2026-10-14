/*
 * main/libmpeg: range (3 files, 0010C658-0010C678)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0010C658 */
#pragma push /* merge_units */
char D_00498838[] __attribute__((aligned(8))) = "_sequenceScalableExtension() is not implemented"; /* 8-aligned in the original data */
extern int func_0010BD90(int, int);

int _sequenceScalableExtension(int a0) {
    return func_0010BD90(a0, (int)D_00498838);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0010C658(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0010C658 */

/* merge_units: begin func_0010C668 */
#pragma push /* merge_units */
char D_00498868[] __attribute__((aligned(8))) = "Unknown Extension"; /* 8-aligned in the original data */

int func_0010C668(int a0) {
    return func_0010BD90(a0, (int)D_00498868);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0010C668(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0010C668 */

/* merge_units: begin func_0010C678 */
#pragma push /* merge_units */
int _pictureSpatialScalableExtension(int a0) {
    return func_0010BD90(a0, (int)"_pictureSpatialScalableExtension is not supported");
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0010C678(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0010C678 */
