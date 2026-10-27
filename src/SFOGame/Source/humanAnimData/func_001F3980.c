#include "types.h"

extern void std_list_imp_voidPtr_ctor(void* self);

#pragma optimization_level 1
/* Calls std_list_imp_voidPtr_ctor on self and returns self (unit built at -O1). */
void* std_list_cSkaTransBLENDPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
#pragma optimization_level reset
