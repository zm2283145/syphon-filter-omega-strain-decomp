#include "types.h"
#pragma optimization_level 1

extern char** std_vector_deleter_cSkaSwitchItem_data(void* v);

/* Returns the data pointer of the vector. */
char* std_vector_imp_cSkaSwitchItem_begin(void* v)
{
    return *std_vector_deleter_cSkaSwitchItem_data(v);
}
