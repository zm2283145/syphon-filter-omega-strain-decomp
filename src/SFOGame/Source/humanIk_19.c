/*
 * SFOGame/Source/humanIk: 2 files, 001D2860-001D2880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D2860 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cJointInfo_CenterPosition_InBoneSpace(char* self) {
    return self + 16;
}

void* func_001D2870(void* self) {
    return self;
}
static inline void merge_flush_func_001D2860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2860 */

/* merge_units: begin func_001D2880 */
#pragma push /* merge_units */
/* Saves slot idx's 3-row matrix (+0x80) into its output block (+0xD0); lq/sq quad copies as asm. */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V& operator=(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct M3 { V r[3]; };
struct Slot { char pad[0x80]; M3 saved; char pad2[0x20]; M3 out; };
extern "C" Slot UpperBodyNodeTable[];
#pragma opt_propagation off
extern "C" void cHumanIkRoutine_UpdateHipBeforeDoingLegIk(void* self, int idx)
{
    Slot* s = &UpperBodyNodeTable[idx]; const M3* o = &s->saved; M3* d = &s->out; *d = *o;
}
static inline void merge_flush_func_001D2880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2880 */
