/*
 * Libs/SFOLib/Source/character: 3 files, 003E46E0-003E4700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E46E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E46E0(char* self, float value) {
    *(float*)(self + 36) = value;
}
static inline void merge_flush_func_003E46E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E46E0 */

/* merge_units: begin func_003E46F0 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { char pad[0x10]; Vec4 v; } S;
/* Copies a vector into +0x10. */
void func_003E46F0(S* dst, Vec4* src) { dst->v = *src; }
static inline void merge_flush_func_003E46F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E46F0 */

/* merge_units: begin func_003E4700 */
#pragma push /* merge_units */
#include "loose04_types.h"

/* Quadword copy. */
void func_003E4700(Q* dst, Q* src) {
    Q tmp;

    tmp = *src;
    *dst = tmp;
}

void func_003E4710(char* self, int value) {
    *(int*)(self + 40) = value;
}
static inline void merge_flush_func_003E4700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4700 */
