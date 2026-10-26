#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_second_void(void* obj);

/* Thin wrapper around details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_second_void. */
void std_vector_deleter_cSkaBlendSequenceItem_cap_void(void* obj) {
    details_compressed_pair_imp_cAllocator_cSkaBlendSequenceItem_int_1_second_void(obj);
}

#pragma pop
