#pragma cplusplus on
#include "types.h"
#include "gated_vcall.h"

/* Run virtual slot 0x48 unless suppressed. */
DEFINE_GATED_VCALL(cPlayerCamera_CriticalNextFrame, GVc281030, VPAD16(a))
