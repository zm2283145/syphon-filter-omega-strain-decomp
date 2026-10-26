#include "types.h"
#pragma optimization_level 1

extern void std_list_imp_voidPtr_ctor(void* self);

/* Calls std_list_imp_voidPtr_ctor on self and returns self. */
void* std_list_cSkaBlendSequenceItemPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
