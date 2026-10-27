/*
 * SFOGame/Source/humanCollision: 2 files, 001ED820-001ED860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED820 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct BitsD8D0 {
    int w[1];
    BitsD8D0() {}
    BitsD8D0(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; }
    BitsD8D0& operator=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
    BitsD8D0& operator&=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] &= o.w[i]; return *this; }
};
extern "C" int cBitArray_5_opAnd(BitsD8D0* out, const BitsD8D0& a, const BitsD8D0& b) {
    BitsD8D0 t(a);
    t &= b;
    *out = t;
    return 0;
}
static inline void merge_flush_func_001ED820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED820 */

/* merge_units: begin func_001ED860 */
#pragma push /* merge_units */
int cBitArray_19_opEq(const int* a, const int* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (*a != *b) return 0;
        b++; a++;
    }
    return 1;
}
static inline void merge_flush_func_001ED860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED860 */
