/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
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
