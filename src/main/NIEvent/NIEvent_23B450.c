/*
 * main/NIEvent: range (2 files, 0023B450-0023B4C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0023B450 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* Mtx_Multiply(V4* a, V4* b) {
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf8, 0x0(a)
        lqc2 vf9, 0x10(a)
        lqc2 vf10, 0x20(a)
        lqc2 vf11, 0x30(a)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
        sqc2 vf11, 0x30(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023B450 */

/* merge_units: begin func_0023B4C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4_23B4C0 { float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_23B4C0 { V4_23B4C0 r[4];
    M4_23B4C0() {}
};
static inline float Rad_23B4C0(float d) { return d * 0.017453292f; }
static inline __int128 LoadQ_23B4C0(const V4_23B4C0* s) { __int128 t; asm { .set noreorder; lq t, 0x0(s); .set reorder } return t; }
static inline void StoreAll_23B4C0(M4_23B4C0* d, const M4_23B4C0* s, __int128 t, V4_23B4C0* pd) { __int128 qa; __int128 qb; asm { .set noreorder; sq t, 0x0(pd); lq qa, 0x0(s); .set reorder; lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
struct K64_23B4C0 { float t; char pad[0x3C]; };
struct K8_23B4C0 { float t; int v; };
struct K16_23B4C0 { float t; char pad[0xC]; };
struct Rot_23B4C0 { float val; int cap; int n; K16_23B4C0* data; int pad10; int state; float t; unsigned char flag; char pad1D[3]; };
extern "C" {
float Vec4_GetX(V4_23B4C0* v);
float Vec4_GetY(V4_23B4C0* v);
float Vec4_GetZ(V4_23B4C0* v);
void Mtx_MakeAxisRotation(M4_23B4C0* m, float x, float y, float z, float a);
void func_001D3E20(M4_23B4C0* m);
#if 0 /* merge_units */
void Mtx_Multiply(M4_23B4C0* a, M4_23B4C0* b);
#endif /* merge_units */
#define Mtx_Multiply(a0, a1) ((void)Mtx_Multiply((V4 *)(a0), (V4 *)(a1))) /* merge_units */

bool NiRotationTrack_Update(Rot_23B4C0* p, float dt);
}
static inline void MakeRot_23B4C0(M4_23B4C0* m, const V4_23B4C0& a, float ang) { Mtx_MakeAxisRotation(m, a.x, a.y, a.z, ang); }
class Elem_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD4(d)
    virtual void Reset();
};
class Self_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Apply();
    VPAD2(e)
    virtual bool Step(float dt);
    virtual bool Step2(float dt);
    char pad4[0x60 - 0x4];
    int mode;
    char pad64[0x9C - 0x64];
    int acap; int an; Elem_23B4C0** adata;
    char padA8[0xB0 - 0xA8];
    int n1; K64_23B4C0* d1;
    char padB8[0xC0 - 0xB8];
    float t1;
    char padC4[0xC8 - 0xC4];
    int n2; K8_23B4C0* d2;
    char padD0[0xD8 - 0xD0];
    float t2;
    char padDC[0xE0 - 0xDC];
    V4_23B4C0 pos;
    M4_23B4C0 mtx;
    unsigned char b130;
    char pad131[0x144 - 0x131];
    Rot_23B4C0 rx;
    Rot_23B4C0 ry;
    Rot_23B4C0 rz;
};
static inline void Finish_23B4C0(Rot_23B4C0* r) {
    r->flag = 1;
    if (r->state == -1)
        NiRotationTrack_Update(r, r->data[(unsigned)(r->n - 1)].t - r->t);
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
extern "C" void cNIEventOBJ_v48(Self_23B4C0* self)
{
    int i;
    self->b130 = 1;
    self->Step(self->d1[(unsigned)(self->n1 - 1)].t - self->t1);
    self->Step2(self->d2[(unsigned)(self->n2 - 1)].t - self->t2);
    Finish_23B4C0(&self->rx);
    Finish_23B4C0(&self->ry);
    Finish_23B4C0(&self->rz);
    if (self->mode != 3) {
        M4_23B4C0 m0;
        V4_23B4C0 ax1;
        V4_23B4C0 ax2;
        V4_23B4C0 ax3;
        M4_23B4C0 m1;
        M4_23B4C0 m2;
        float ang;
        ang = Rad_23B4C0(self->rx.val);
        ax1.Set(1.0f, 0.0f, 0.0f, 0.0f);
        Mtx_MakeAxisRotation(&m0, Vec4_GetX(&ax1), Vec4_GetY(&ax1), Vec4_GetZ(&ax1), ang);
        ang = Rad_23B4C0(self->ry.val);
        ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
        func_001D3E20(&m1);
        MakeRot_23B4C0(&m1, ax2, ang);
        Mtx_Multiply(&m0, &m1);
        ang = Rad_23B4C0(self->rz.val);
        ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
        func_001D3E20(&m2);
        MakeRot_23B4C0(&m2, ax3, ang);
        Mtx_Multiply(&m0, &m2);
        StoreAll_23B4C0(&self->mtx, &m0, LoadQ_23B4C0(&self->pos), &m0.r[3]);
    }
    self->Apply();
    for (i = 0; i < self->an; i++)
        self->adata[i]->Reset();
}
#pragma pop
#undef Mtx_Multiply /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B4C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023B4C0 */
