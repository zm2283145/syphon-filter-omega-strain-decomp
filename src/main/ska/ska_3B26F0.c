/*
 * main/ska: range (2 files, 003B26F0-003B2700)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003B26F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


int cPointer_cSkaAnimData_opCast_constcSkaAnimDataPtr(char* self) {
    return *(int*)(self + 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B26F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B26F0 */

/* merge_units: begin func_003B2700 */
#pragma push /* merge_units */
typedef struct SkaClip {
    char pad[0x40];
    int grouping;
} SkaClip;

typedef struct GroupingPair {
    SkaClip* clip;
    int grouping;
} GroupingPair;

/* Fills (clip, grouping); clip is NULL unless the clip's grouping is -1. */
void cSkaAnim_PlaybackGroupId(GroupingPair* out, SkaClip* clip) {
    out->clip = clip->grouping == -1 ? clip : 0;
    out->grouping = clip->grouping;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2700 */
