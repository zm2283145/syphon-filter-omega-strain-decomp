#include "types.h"
typedef union { float f[4]; __int128 q; } V4;
static inline V4 neg4v_(V4* b) {
    V4 r; V4* p = &r;
    asm {
        lqc2 vf1, 0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0(p)
    }
    return r;
}
static inline void add3_(V4* d, V4* a, V4* b) {
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(d)
    }
}
#pragma push
#pragma opt_common_subs off
V4* func_001D56E0(V4* a, V4* b) {
    V4 n = neg4v_(b);
    add3_(a, a, &n);
    return a;
}
#pragma pop