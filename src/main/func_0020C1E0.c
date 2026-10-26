#include "types.h"
extern int* std_vector_deleter_cSkaSwitchItem_cap_void_2(void* p);
#pragma optimization_level 1
int std_vector_imp_cSkaSwitchItem_capacity(void* p)
{
    return *std_vector_deleter_cSkaSwitchItem_cap_void_2(p);
}
#pragma optimization_level reset