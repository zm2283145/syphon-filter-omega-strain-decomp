#pragma cplusplus on
#include "types.h"
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor (built at -O1). */
#pragma optimization_level 1
DEFINE_DIRECT_BASE_DTOR(cLList_cSkaBlendSequenceItemPtr_dtor, std_list_cSkaBlendSequenceItemPtr_dtor)
#pragma optimization_level reset
