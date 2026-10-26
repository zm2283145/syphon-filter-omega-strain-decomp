/*
 * main/human: range (3 files, 00190990-001909D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00190990 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSkaAnimDataSample_DeltaTranslation(char* self) {
    return self + 32;
}

int RootClip_TranslationEnabled(G14* s) {
    return s->v != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190990 */

/* merge_units: begin func_001909B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; unsigned int mask; } BitObj;

/* Returns 1 if bit n of the mask at +0x1C is set. */
int cSkaAnimData_BoneHasTranslation(BitObj* self, int n)
{
    return (self->mask & (1 << n)) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001909B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001909B0 */

/* merge_units: begin func_001909D0 */
#pragma push /* merge_units */
/* Address of field +0x10 in 32-byte element i. */
char* cSkeletonData_GetBoneData(char* base, int i) {
    return base + (i << 5) + 16;
}

int cSkeletonData_GetBoneCount(char* self) {
    return *(int*)(self + 0);
}

void* cSkaAnimDataSample_IsEndOfData(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001909D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001909D0 */
