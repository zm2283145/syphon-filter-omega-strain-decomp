#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x170]; V4 a; char pad2[0x10]; V4 b; } O_3851C0;
typedef struct { char pad[0x2410]; O_3851C0* o; } S_3851C0;
static inline void Add3_(V4* a, V4* d, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4 func_003851C0(S_3851C0* s) {
    V4 r;
    O_3851C0* o = s->o;
    if (o) {
        V4* pc = &r; V4* pd = &r; V4* pa = &r;
        VCopyF(pc, &o->a);
        Add3_(pa, pd, &s->o->b);
        return r;
    }
    { V4* z = &r; V4StoreZero(z); }
    return r;
}
#pragma pop