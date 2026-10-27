/*
 * SFOGame/Source/humanAnimData: 1 file, 00201B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201B60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char c; } Tag_201B60;
extern int std_vector_imp_cSkaBlendSequenceItem_begin_void(void* o);
extern int std_vector_imp_cSkaBlendSequenceItem_end_void_2(void* o);
extern void std_vector_imp_cSkaBlendSequenceItem_do_assign(void* self, int first, int last, Tag_201B60 t);
void* std_vector_imp_cSkaBlendSequenceItem_opAssign(void* self, void* o)
{
    if (self != o) {
        Tag_201B60 t;
        int first = std_vector_imp_cSkaBlendSequenceItem_begin_void(o);
        std_vector_imp_cSkaBlendSequenceItem_do_assign(self, first, std_vector_imp_cSkaBlendSequenceItem_end_void_2(o), t);
    }
    return self;
}
static inline void merge_flush_func_00201B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201B60 */
