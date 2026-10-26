#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_swap(void* self);

/* Forwards to details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_swap. */
void compressed_pair_cAllocator_cSkaTransBLEND_int_swap(void* self)
{
    details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_swap(self);
}
