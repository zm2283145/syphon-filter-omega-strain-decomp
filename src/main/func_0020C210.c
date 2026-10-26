#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_second_void_2(void* self);

/* Forwards to details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_second_void_2. */
void std_vector_deleter_cSkaSwitchItem_cap_void_2(void* self)
{
    details_compressed_pair_imp_cAllocator_cSkaSwitchItem_int_1_second_void_2(self);
}
