#include "types.h"
#include "vu0_ops.h"
int cQuaternion_IsZeroXYZ(void* v) {
    return VU0_IsZero3(v);
}
