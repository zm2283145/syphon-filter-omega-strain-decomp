#pragma cplusplus on
#include "types.h"
#include "gated_vcall.h"

/* Run virtual slot 0x50 unless suppressed. */
DEFINE_GATED_VCALL(func_00280F20, GVc280F20, VPAD16(a) VPAD2(b))
