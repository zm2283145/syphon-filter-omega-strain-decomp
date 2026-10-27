/*
 * SFOGame/Source/humanAnimData: 3 files, 00201DC0-00201E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201DC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
#if 0 /* merge_units */
extern void compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(Obj* self, int a, int b);
#endif /* merge_units */
Word * compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(); /* merge_units */


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

/* merge_units: begin func_00201E00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(Word*, int, int);
#if 0 /* merge_units */
extern Word* cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(Word*);
#endif /* merge_units */
void * cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(); /* merge_units */


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

/* merge_units: begin func_00201E70 */
#pragma push /* merge_units */
extern int details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_first_void(int);

void* cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(void* self) {
    return self;
}

int std_vector_deleter_cSkaBlendSequenceItem_alloc_void(int a0) {
    return details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_first_void(a0);
}
static inline void merge_flush_func_00201E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201E70 */
