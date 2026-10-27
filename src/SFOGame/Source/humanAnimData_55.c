/*
 * SFOGame/Source/humanAnimData: 1 file, 00201BC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201BC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int a; int b; int c; } Elem12;
typedef struct { int unk0; int index; } ElemRef;

extern Elem12** std_vector_deleter_cSkaBlendSequenceItem_data_void_2(ElemRef* self);

/* Returns a pointer to the referenced element of the array returned by std_vector_deleter_cSkaBlendSequenceItem_data_void_2. */
Elem12* std_vector_imp_cSkaBlendSequenceItem_end_void_2(ElemRef* self)
{
    return &(*std_vector_deleter_cSkaBlendSequenceItem_data_void_2(self))[self->index];
}
static inline void merge_flush_func_00201BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201BC0 */
