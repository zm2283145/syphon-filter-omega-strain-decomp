/*
 * main/human: range (2 files, 00185060-00185090)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00185060 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char g_HumanActorClassKey[];

int func_00185060(char* self, int* key) {
    return *(int*)(self + 76) == *key;
}

void* Actor_GetHumanClassKeyPtr(void) {
    return g_HumanActorClassKey;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185060 */

/* merge_units: begin func_00185090 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads a little-endian 32-bit float from the network read cursor. */
void NetRead_Float(float* out)
{
    int bits[1];
    unsigned short lo = read16();
    bits[0] = lo + ((unsigned short)read16() << 16);
    *out = *(float*)bits;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185090(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185090 */
