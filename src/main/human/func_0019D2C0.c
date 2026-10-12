#include "types.h"
typedef struct { float v[4]; } __attribute__((aligned(16))) V4D4;
typedef struct { float m[3][4]; V4D4 pos; } MtxD4;
typedef struct { V4D4 quat; V4D4 pos; } Placement;
static inline MtxD4* QuatToMtx_19D2C0(MtxD4* a, V4D4* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}static inline MtxD4* FromBasis_19D2C0(MtxD4* d, MtxD4* b, V4D4* p)
{
    d->m[0][0] = b->m[0][0];
    d->m[0][1] = b->m[0][1];
    d->m[0][2] = b->m[0][2];
    d->m[1][0] = b->m[1][0];
    d->m[1][1] = b->m[1][1];
    d->m[1][2] = b->m[1][2];
    d->m[2][0] = b->m[2][0];
    d->m[2][1] = b->m[2][1];
    d->m[2][2] = b->m[2][2];
    d->m[0][3] = b->m[0][3];
    d->m[1][3] = b->m[1][3];
    d->m[2][3] = b->m[2][3];
    d->pos = *p;
    return d;
}
#pragma inline_depth(10)
#pragma peephole off
#pragma opt_propagation off
static inline V4D4* PlGetQuat_19D2C0(Placement* p) { return &p->quat; }
static inline V4D4* PlGetPos_19D2C0(Placement* p) { return &p->pos; }
MtxD4* Placement_ToMatrix(MtxD4* out, Placement* pl)
{
    MtxD4 rot;
    V4D4* pos = PlGetPos_19D2C0(pl);
    QuatToMtx_19D2C0(&rot, PlGetQuat_19D2C0(pl));
    return FromBasis_19D2C0(out, &rot, pos);
}



