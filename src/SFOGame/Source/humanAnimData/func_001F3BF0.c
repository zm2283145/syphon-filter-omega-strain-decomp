/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(Word*, int);
extern Word* cAllocator_cSkaBlendSequenceItem_ctor_void(Word*);

Word* compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(Word* self, int value) {
    details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(self, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_uint(Word* self, int value) {
    cAllocator_cSkaBlendSequenceItem_ctor_void(self);
    self->value = value;
    return self;
}
