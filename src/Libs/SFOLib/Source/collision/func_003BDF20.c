#include "types.h"
#include "vu0_ops.h"
int cVector_IsZero(void* v) {
    return VU0_IsZero4(v);
}
