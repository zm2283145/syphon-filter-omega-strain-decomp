#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void std_swap_vectordeleterR_vectordeleterR_14(void* self);

/* Forwards to std_swap_vectordeleterR_vectordeleterR_14. */
void std_vector_deleter_cSkaBlendSequenceItem_swap(void* self)
{
    std_swap_vectordeleterR_vectordeleterR_14(self);
}
