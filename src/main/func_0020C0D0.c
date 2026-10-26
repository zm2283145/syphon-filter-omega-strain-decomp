#include "types.h"
extern void std_vector_imp_cSkaTransBLEND_ctor_vectorimpR(void* self);
#pragma optimization_level 1
void* std_vector_cSkaTransBLEND_ctor_vectorR(void* self)
{
    std_vector_imp_cSkaTransBLEND_ctor_vectorimpR(self);
    return self;
}
#pragma optimization_level reset