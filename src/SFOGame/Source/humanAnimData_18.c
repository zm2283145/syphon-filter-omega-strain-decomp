/*
 * SFOGame/Source/humanAnimData: 1 file, 001F3060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3060 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* std_vector_cSkaSwitchItem_ctor(ObjVec*);
extern ObjVec* std_vector_imp_cSkaSwitchItem_ctor_void(ObjVec*);
extern ObjVec* std_vector_deleter_cSkaSwitchItem_ctor_void(ObjVec*);

void* details_compressed_pair_imp_cAllocator_voidPtr_int_1_second(void* self) {
    return self;
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* cArray_cSkaSwitchItem_ctor_void(ObjVec* self) {
    std_vector_cSkaSwitchItem_ctor(self);
    self->owned = 1;
    return self;
}

ObjVec* std_vector_cSkaSwitchItem_ctor(ObjVec* self) {
    std_vector_imp_cSkaSwitchItem_ctor_void(self);
    return self;
}

ObjVec* std_vector_imp_cSkaSwitchItem_ctor_void(ObjVec* self) {
    std_vector_deleter_cSkaSwitchItem_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F3060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3060 */
