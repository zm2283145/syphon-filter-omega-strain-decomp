#pragma cplusplus on
#include "types.h"
#include "gated_vcall.h"

/* Run virtual slot 0x48 unless suppressed. */
DEFINE_GATED_VCALL(PlayerCamera_v11, GVc281030, VPAD16(a))
