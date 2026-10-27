/*
 * SFOGame/Source/humanAnimData: 1 file, 00201DC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201DC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(Obj* self, int a, int b);

/* Constructor: base init then clears +4/+8. */
Obj* std_vector_deleter_cSkaBlendSequenceItem_ctor_cAllocatorR(Obj* self, int a)
{
    compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(self, a, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
static inline void merge_flush_func_00201DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201DC0 */
