#include "types.h"

extern void std_copy_backward_cSkaBlendSequenceItem_copy_backward(void* self);

#pragma optimization_level 1
/* Forwards to std_copy_backward_cSkaBlendSequenceItem_copy_backward (unit built at -O1: no tail call). */
void std_copy_backward_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(void* self)
{
    std_copy_backward_cSkaBlendSequenceItem_copy_backward(self);
}
#pragma optimization_level reset
