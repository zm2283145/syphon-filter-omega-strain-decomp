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


void* func_00190990(char* self) {
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
int func_001909B0(BitObj* self, int n)
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
char* func_001909D0(char* base, int i) {
    return base + (i << 5) + 16;
}

int func_001909E0(char* self) {
    return *(int*)(self + 0);
}

void* func_001909F0(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001909D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001909D0 */
