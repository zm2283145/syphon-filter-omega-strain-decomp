/*
 * main/human: range (2 files, 0019D250-0019D2C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019D250 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D250;
typedef struct { V4_D250 r[4]; } M4_D250;
extern float Libc_Atan2f(float y, float x);
static inline float GetX_D250(V4_D250* v) { return v->x; }
static inline float GetY_D250(V4_D250* v) { return v->y; }
static inline float GetZ_D250(V4_D250* v) { return v->z; }
static inline float H180_D250(V4_D250* v) { return Libc_Atan2f(GetY_D250(v), GetX_D250(v)); }
static inline float H170_D250(float* v) { return Libc_Atan2f(-v[0], v[1]); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
float Mtx_GetHeading(M4_D250* m)
{
    V4_D250 r0;
    V4_D250 r1;
    V4_D250* d0 = &r0;
    asm { .set reorder } /* empty barrier keeps the &r0 addiu ahead of the row loads (known trick) */
    *d0 = m->r[0];
    r1 = m->r[1];
    return GetZ_D250(&r0) < GetZ_D250(&r1) ? H180_D250(&r0) : H170_D250(&r1.x);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D250 */

/* merge_units: begin func_0019D2C0 */
#pragma push /* merge_units */
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
MtxD4* cMatrix_ctor_cQuatVecR(MtxD4* out, Placement* pl)
{
    MtxD4 rot;
    V4D4* pos = PlGetPos_19D2C0(pl);
    QuatToMtx_19D2C0(&rot, PlGetQuat_19D2C0(pl));
    return FromBasis_19D2C0(out, &rot, pos);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D2C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D2C0 */
