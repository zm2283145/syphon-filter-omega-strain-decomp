/*
 * SFOGame/Source/humanAnimData: 2 files, 001F3A70-001F3AB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3A70 */
#pragma push /* merge_units */
#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

extern void std_list_imp_voidPtr_ctor(void* self);

/* Runs std_list_imp_voidPtr_ctor on self and returns self. */
void* std_list_cSkaSwitchItemPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
static inline void merge_flush_func_001F3A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3A70 */

/* merge_units: begin func_001F3AB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_imp_cSkaBlendSequenceItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_deleter_cSkaBlendSequenceItem_ctor_void(ObjVec*);

MotionEntry24* cSkaTransBLEND_ctor_float_bool_bool(MotionEntry24* self, int a1, int a2, float f) {
    cArray_cSkaBlendSequenceItem_ctor_void(&self->list);
    self->unk10 = f;
    self->unk14 = f;
    self->unk18 = -1;
    self->unk1C = a1;
    self->unk1D = a2;
    self->unk20 = -1;
    return self;
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* cArray_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_cSkaBlendSequenceItem_ctor_void(self);
    self->owned = 1;
    return self;
}

ObjVec* std_vector_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_imp_cSkaBlendSequenceItem_ctor_void(self);
    return self;
}

ObjVec* std_vector_imp_cSkaBlendSequenceItem_ctor_void(ObjVec* self) {
    std_vector_deleter_cSkaBlendSequenceItem_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F3AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3AB0 */
