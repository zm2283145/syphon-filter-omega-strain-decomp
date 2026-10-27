/*
 * SFOGame/Source/humanAnimData: 1 file, 001F3BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3BB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

extern void compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(Obj3* self, int arg);

/* Constructor: base init with 0, then clears the two following words. */
Obj3* std_vector_deleter_cSkaBlendSequenceItem_ctor_void(Obj3* self) {
    compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
static inline void merge_flush_func_001F3BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3BB0 */
