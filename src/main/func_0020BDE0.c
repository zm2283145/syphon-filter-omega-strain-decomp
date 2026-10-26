#include "types.h"
#pragma optimization_level 1

extern void std_vector_imp_cSkaTransBLEND_opAssign(void*);

/* Calls std_vector_imp_cSkaTransBLEND_opAssign(self) and returns self. */
void* std_vector_cSkaTransBLEND_opAssign(void* self) {
    std_vector_imp_cSkaTransBLEND_opAssign(self);
    return self;
}
