/*
 * SFOGame/Source/humanAnimData: 1 file, 00201D50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201D50 */
#pragma push /* merge_units */
#include "types.h"

extern int std_vector_deleter_cSkaBlendSequenceItem_alloc_void(void* src);
extern void std_vector_deleter_cSkaBlendSequenceItem_ctor_cAllocatorR(void* self, int value);
extern int std_vector_imp_cSkaBlendSequenceItem_begin_void(void* src);
extern int std_vector_imp_cSkaBlendSequenceItem_end_void_2(void* src);
extern void std_vector_imp_cSkaBlendSequenceItem_init(void* self, int first, int last, char alloc);

/* Copy-constructs self from src: header, then the range [begin, end) of src. */
void* std_vector_imp_cSkaBlendSequenceItem_ctor_vectorimpR(void* self, void* src) {
    volatile char alloc[4];
    int first, last;
    std_vector_deleter_cSkaBlendSequenceItem_ctor_cAllocatorR(self, std_vector_deleter_cSkaBlendSequenceItem_alloc_void(src));
    first = std_vector_imp_cSkaBlendSequenceItem_begin_void(src);
    last = std_vector_imp_cSkaBlendSequenceItem_end_void_2(src);
    std_vector_imp_cSkaBlendSequenceItem_init(self, first, last, alloc[0]);
    return self;
}
static inline void merge_flush_func_00201D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201D50 */
