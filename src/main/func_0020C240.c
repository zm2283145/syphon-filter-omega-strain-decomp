#include "types.h"
extern void* std_vector_deleter_cSkaSwitchItem_alloc_void_2(void);
extern void cAllocator_cSkaSwitchItem_max_size(void* p);
/* Passes the result of std_vector_deleter_cSkaSwitchItem_alloc_void_2 to cAllocator_cSkaSwitchItem_max_size. */
#pragma optimization_level 1
void std_vector_imp_cSkaSwitchItem_max_size(void) { cAllocator_cSkaSwitchItem_max_size(std_vector_deleter_cSkaSwitchItem_alloc_void_2()); }
#pragma optimization_level reset
