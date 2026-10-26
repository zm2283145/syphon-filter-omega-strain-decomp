#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int* std_vector_deleter_cSkaBlendSequenceItem_cap_void_2(void* obj);

/* Returns the int pointed to by std_vector_deleter_cSkaBlendSequenceItem_cap_void_2's result. */
int std_vector_imp_cSkaBlendSequenceItem_capacity(void* obj) {
    return *std_vector_deleter_cSkaBlendSequenceItem_cap_void_2(obj);
}

#pragma pop
