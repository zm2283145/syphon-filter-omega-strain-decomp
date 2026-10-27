#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

extern void std_list_imp_voidPtr_ctor(void* self);

/* Runs std_list_imp_voidPtr_ctor on self and returns self. */
void* std_list_cSkaSwitchItemPtr_ctor(void* self)
{
    std_list_imp_voidPtr_ctor(self);
    return self;
}
