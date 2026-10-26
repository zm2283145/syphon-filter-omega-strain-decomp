#include "types.h"

extern int* std_vector_deleter_cSkaTransBLEND_data_void(void* self);

#pragma optimization_level 1
/* Returns the int pointed to by std_vector_deleter_cSkaTransBLEND_data_void's result. */
int std_vector_imp_cSkaTransBLEND_begin_void(void* self)
{
    return *std_vector_deleter_cSkaTransBLEND_data_void(self);
}
#pragma optimization_level reset
