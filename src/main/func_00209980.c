#include "types.h"
#pragma optimization_level 1

extern int std_vector_deleter_cSkaBlendSequenceItem_alloc_void(void);
extern void cAllocator_cSkaBlendSequenceItem_max_size(int);

/* Passes the result of std_vector_deleter_cSkaBlendSequenceItem_alloc_void to cAllocator_cSkaBlendSequenceItem_max_size. */
void std_vector_imp_cSkaBlendSequenceItem_max_size(void) {
    cAllocator_cSkaBlendSequenceItem_max_size(std_vector_deleter_cSkaBlendSequenceItem_alloc_void());
}
