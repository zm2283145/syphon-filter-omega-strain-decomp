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
