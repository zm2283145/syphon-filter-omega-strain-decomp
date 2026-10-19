#pragma cplusplus on
#include "types.h"
#include "gated_vcall.h"

/* Run virtual slot 0x50 unless suppressed. */
DEFINE_GATED_VCALL(PlayerCamera_v13, GVc280F20, VPAD16(a) VPAD2(b))
