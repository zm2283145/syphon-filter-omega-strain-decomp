/*
 * SFOGame/Source/NIEvent: 1 file, 0023D6C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023D6C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of element i in an array of 0x40-byte records whose base pointer is at +8. */
char* std_vector_VectorKey_opIndex(char* self, int i) {
    return *(char**)(self + 8) + (i << 6);
}
static inline void merge_flush_func_0023D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D6C0 */
