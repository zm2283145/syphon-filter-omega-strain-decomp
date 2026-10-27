/*
 * SFOGame/Source/gameCameraCollision: 1 file, 0020CC20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020CC20 */
#pragma push /* merge_units */
#include "types.h"
#pragma optimization_level 1

/* Empty tag object passed by value. */
typedef struct Tag {
    signed char unused;
} Tag;

extern void std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(int, int, Tag);

/* Forwards to std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag with a default tag. */
void std_distance_cSkaTransBLENDP_cSkaTransBLENDP(int a, int b) {
    Tag tag;
    std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(a, b, tag);
}
static inline void merge_flush_func_0020CC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CC20 */
