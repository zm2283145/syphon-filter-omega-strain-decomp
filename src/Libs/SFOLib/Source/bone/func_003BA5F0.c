#pragma cplusplus on
#include "types.h"
/* cBone_AnimationSetWeightedOffset: push the accumulated translation, or restore the bind position */
typedef struct Vec3BT { float x, y, z; } Vec3BT;
struct Vec4BT {
    float x, y, z, w;
    Vec4BT() {}
    Vec4BT(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
typedef struct XfBT { int a, b; Vec3BT pos; } XfBT;
struct BoneBT {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4BT* p);
    char pad[0xBC];
    XfBT* xf;
    char padC4[0x180 - 0xC4];
    Vec4BT accumT;
    Vec4BT accumR;
    char pad1A0[0x10];
    Vec4BT pos;
};
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline int IsZero(const Vec4BT* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
extern "C" void cBone_AnimationSetWeightedOffset(BoneBT* b)
{
    if (!IsZero(&b->accumT)) {
        b->accumT.w = 1.0f;
        b->SetPos(&b->accumT);
        VC(&b->pos, &b->accumT);
    } else if (IsZero(&b->pos)) {
        XfBT* xf = b->xf;
        Vec4BT* q;
        Vec4BT v(xf->pos.x, xf->pos.y, xf->pos.z);
        Vec4BT* p = &b->pos;
        VC(p, &v);
        q = &b->pos; q->w = 1.0f;
    }
}
