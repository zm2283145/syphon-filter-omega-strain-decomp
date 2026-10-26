#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void std_copy_backward_cSkaTransBLEND_copy_backward(void* obj);

/* Thin wrapper around std_copy_backward_cSkaTransBLEND_copy_backward. */
void std_copy_backward_cSkaTransBLENDP_cSkaTransBLENDP_cSkaTransBLENDP(void* obj) {
    std_copy_backward_cSkaTransBLEND_copy_backward(obj);
}

#pragma pop
