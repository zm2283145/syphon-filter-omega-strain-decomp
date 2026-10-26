#include "types.h"

/* Built at a lower optimization level (keeps a real call and frame). */
#pragma optimization_level 2

extern int* std_vector_deleter_cSkaTransBLEND_data_void_2(void* self);

/* Returns the word pointed to by std_vector_deleter_cSkaTransBLEND_data_void_2(self). */
int std_vector_imp_cSkaTransBLEND_begin_void_2(void* self)
{
    return *std_vector_deleter_cSkaTransBLEND_data_void_2(self);
}
