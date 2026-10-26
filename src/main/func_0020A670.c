#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void std_fill_n_cSkaBlendSequenceItem_int_fill_n(void* obj);

/* Thin wrapper around std_fill_n_cSkaBlendSequenceItem_int_fill_n. */
void std_fill_n_cSkaBlendSequenceItemP_uint_cSkaBlendSequenceItemR(void* obj) {
    std_fill_n_cSkaBlendSequenceItem_int_fill_n(obj);
}

#pragma pop
