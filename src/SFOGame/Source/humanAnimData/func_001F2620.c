#pragma cplusplus on
#include "types.h"
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(std_list_cSkaSwitchItemPtr_dtor, func_00135C90)
#pragma optimization_level reset
