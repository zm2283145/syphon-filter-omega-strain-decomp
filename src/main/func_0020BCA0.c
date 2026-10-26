#include "types.h"

extern void std_fill_n_cSkaSwitchItem_int_fill_n(void* self);

#pragma optimization_level 1
/* Forwards to std_fill_n_cSkaSwitchItem_int_fill_n (unit built at -O1: no tail call). */
void std_fill_n_cSkaSwitchItemP_uint_cSkaSwitchItemR(void* self)
{
    std_fill_n_cSkaSwitchItem_int_fill_n(self);
}
#pragma optimization_level reset
