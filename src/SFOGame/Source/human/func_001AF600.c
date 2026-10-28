#include "types.h"
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_propagation off
#pragma opt_common_subs off

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

/* cBone_SkeletonBBoxContribution (human.cc) */
typedef struct {
    unsigned char doesBoneContribute;
    unsigned char isOffsetZero;
    char pad02[2];
    float contributionPointRadius;
    char pad08[8];
    V contributionPointOffset;
} Obj1AF600;

static inline V AsPoint(const V& src) {
    asm { .set reorder } /* scheduling: ends the noreorder region the VU0 test leaves open */
    V t(src);
    V* p = &t; p->w = 1.0f;
    return *p;
}

/* VU0 offset-is-zero test; the block deliberately does not restore .set reorder (see AsPoint) */
static inline bool IsZeroXYZ(const V* v)
{
    int k, fl;
    bool r = false;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
    }
    return r;
}

static inline void Ctor_(Obj1AF600* o, float f, V vv) {
    o->doesBoneContribute = 1;
    o->isOffsetZero = IsZeroXYZ(&vv);
    o->contributionPointRadius = f;
    o->contributionPointOffset = AsPoint(vv);
}

/* Reset: placement-construct the contribution in place (new (this) T(radius, offset)). */
extern "C" void cBone_SkeletonBBoxContribution_Reset(Obj1AF600* o, V* v, float f) {
    if (o) {
        Ctor_(o, f, *v);
    }
}
