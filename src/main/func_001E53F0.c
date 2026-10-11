#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4_ func_001E53F0(const V4_* v, float z) {
    V4_ t;
    V4_* d = &t;
    VCopyF(d, v);
    {
        V4_* e = &t;
        e->z = z;
        return *e;
    }
}
#pragma pop