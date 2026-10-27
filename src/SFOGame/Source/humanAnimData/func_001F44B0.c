#include "types.h"

extern void std_list_cSkaBlendSequenceItemPtr_ctor(void* self);

#pragma optimization_level 1
/* Calls std_list_cSkaBlendSequenceItemPtr_ctor on self and returns self (unit built at -O1). */
void* cLList_cSkaBlendSequenceItemPtr_ctor(void* self)
{
    std_list_cSkaBlendSequenceItemPtr_ctor(self);
    return self;
}
#pragma optimization_level reset
