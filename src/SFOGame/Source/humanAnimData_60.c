/*
 * SFOGame/Source/humanAnimData: 1 file, 00201E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201E00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(Word*, int, int);
extern Word* cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(Word*);

Word* compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(Word* self, int unused, int value) {
    details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(self, unused, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(Word* self, int unused, int value) {
    cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(self);
    self->value = value;
    return self;
}
static inline void merge_flush_func_00201E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201E00 */
