/*
 * main/human: range (4 files, 001AE050-001AE0D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001AE050 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_001AE050(int a0, int a1, int a2, int a3) {
    int v0, v1;

    v1 = 0 + 1;
    v0 = (signed char)a1;
    v0 = v0 << 3;
    a1 = v0 + a0;
    *(int*)(char*)(a1 + 4) = a2;
    v0 = a0;
    *(int*)(char*)(a1 + 8) = a3;
    *(char*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE050 */

/* merge_units: begin func_001AE080 */
#pragma push /* merge_units */
typedef struct { int unk0; int bits[1]; } BitSet001AE080;
/* Test bit `index` of a bitset that starts at offset 4. */
int BitSet_Test(BitSet001AE080* set, unsigned char index)
{
    unsigned int i = index;
    return ((set->bits[i >> 5] >> (i & 0x1F)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE080 */

/* merge_units: begin func_001AE0B0 */
#pragma push /* merge_units */
unsigned char func_001AE0B0(unsigned char* self, int i) {
    return self[((i & 255) << 1) + 978];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE0B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE0B0 */

/* merge_units: begin func_001AE0D0 */
#pragma push /* merge_units */
typedef struct BitSetOwner {
    char pad0000[0x3204];
    int bits[8]; /* 0x3204 */
} BitSetOwner;

/* Tests bit `index` in the 256-bit set at +0x3204. */
int cHuman_CheckState(BitSetOwner* obj, unsigned char index) {
    return ((obj->bits[(unsigned int)index >> 5] >> (index & 0x1F)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE0D0 */
