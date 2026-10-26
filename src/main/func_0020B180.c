#include "types.h"
#include "identity_return.h"

/* Return the argument unchanged. */
#pragma optimization_level 1
DEFINE_IDENTITY_RETURN(cSkaTrans_opAssign)
#pragma optimization_level reset
