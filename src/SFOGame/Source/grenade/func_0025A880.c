#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_A880;
static inline V4_A880 Sub_A880(V4_A880* a, V4_A880* b) {
    V4_A880 r; V4_A880* p = &r;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma opt_common_subs off
int ClipSegmentToZRange(V4_A880* a, V4_A880* b, float lo, float hi) {
    V4_A880 d = Sub_A880(b, a);
    float t;
    float z;
    z = a->z;
    if (z > hi) {
        if (b->z > hi) return 0;
        t = (hi - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = hi;
    } else if (z < lo) {
        if (b->z < lo) return 0;
        t = (lo - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = lo;
    }
    z = b->z;
    if (z > hi) {
        t = (hi - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = hi;
    } else if (z < lo) {
        t = (lo - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = lo;
    }
    return 1;
}