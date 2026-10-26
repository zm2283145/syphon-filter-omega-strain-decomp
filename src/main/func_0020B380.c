#include "types.h"

extern void* std_vector_deleter_cSkaTransBLEND_alloc_void_2(void* self);
extern void cAllocator_cSkaTransBLEND_max_size(void* p);

#pragma optimization_level 1
/* Passes the result of std_vector_deleter_cSkaTransBLEND_alloc_void_2 to cAllocator_cSkaTransBLEND_max_size (unit built at -O1). */
void std_vector_imp_cSkaTransBLEND_max_size(void* self)
{
    cAllocator_cSkaTransBLEND_max_size(std_vector_deleter_cSkaTransBLEND_alloc_void_2(self));
}
#pragma optimization_level reset
