#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4_ func_003E5EF0(const V4_* v) {
    V4_ t;
    float zf = 0.0f;
    V4_* d = &t;
    VCopyF(d, v);
    {
        V4_* e = &t;
        e->w = zf;
        return *e;
    }
}
#pragma pop