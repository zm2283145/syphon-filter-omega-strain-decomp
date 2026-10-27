#include "types.h"

extern void std_list_cSkaSwitchItemPtr_push_back(void* self);

#pragma optimization_level 1
/* Forwards to std_list_cSkaSwitchItemPtr_push_back (unit built at -O1: no tail call). */
void cLList_cSkaSwitchItemPtr_PushBackActual(void* self)
{
    std_list_cSkaSwitchItemPtr_push_back(self);
}
#pragma optimization_level reset
