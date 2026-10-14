/*
 * main/human: range (2 files, 0019D760-0019D790)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_0019D760 */
#pragma push /* merge_units */
/* Returns 1 if bit n is set in the bit array. */
int BitArray_Test(int* bits, int n)
{
    return ((bits[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D760 */

/* merge_units: begin func_0019D790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern AnimChannel* Model_GetChannelData(ChannelVec*, int);

/* Current value of a channel in the collection at +0x88 (index is not set by the caller-side code). */
float AnimChannel_GetCurrentValue(char* owner) {
    int index;

    return Model_GetChannelData((ChannelVec*)(owner + 136), index)->base.current;
}

/* Current value of channel i in the collection at +0x78. */
float AnimChannel_GetCurrent(char* owner, int i) {
    ChannelVec* v = (ChannelVec*)(owner + 120);

    return ((AnimChannel*)((char*)v->data + (((i << 4) - i) << 2)))->base.current;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D790 */
