/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(Word*, int, int);
extern Word* cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(Word*);

Word* compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_cAllocatorR_uint(Word* self, int unused, int value) {
    details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(self, unused, value);
    return self;
}

Word* details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_ctor_cAllocatorR_uint(Word* self, int unused, int value) {
    cAllocator_cSkaBlendSequenceItem_ctor_cAllocatorR(self);
    self->value = value;
    return self;
}
