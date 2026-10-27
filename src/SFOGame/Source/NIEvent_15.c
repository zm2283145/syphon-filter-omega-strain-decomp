/*
 * SFOGame/Source/NIEvent: 3 files, 0023B450-0023B7D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023B450 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cMatrix_Rotate(V4* a, V4* b) {
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
float cVector_X_void(V4_23B4C0* v);
float cVector_Y_void(V4_23B4C0* v);
float cVector_Z_void(V4_23B4C0* v);
void cMatrix_SetWithAxisAngle(M4_23B4C0* m, float x, float y, float z, float a);
void cMatrix_ctor_void(M4_23B4C0* m);
#if 0 /* merge_units */
void cMatrix_Rotate(M4_23B4C0* a, M4_23B4C0* b);
#endif /* merge_units */
#define cMatrix_Rotate(a0, a1) ((void)cMatrix_Rotate((V4 *)(a0), (V4 *)(a1))) /* merge_units */


bool cNIEventFloatTrack_Update(Rot_23B4C0* p, float dt);
}
static inline void MakeRot_23B4C0(M4_23B4C0* m, const V4_23B4C0& a, float ang) { cMatrix_SetWithAxisAngle(m, a.x, a.y, a.z, ang); }
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
        cNIEventFloatTrack_Update(r, r->data[(unsigned)(r->n - 1)].t - r->t);
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
extern "C" void cNIEventOBJ_SetEndState(Self_23B4C0* self)
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
        cMatrix_SetWithAxisAngle(&m0, cVector_X_void(&ax1), cVector_Y_void(&ax1), cVector_Z_void(&ax1), ang);
        ang = Rad_23B4C0(self->ry.val);
        ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
        cMatrix_ctor_void(&m1);
        MakeRot_23B4C0(&m1, ax2, ang);
        cMatrix_Rotate(&m0, &m1);
        ang = Rad_23B4C0(self->rz.val);
        ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
        cMatrix_ctor_void(&m2);
        MakeRot_23B4C0(&m2, ax3, ang);
        cMatrix_Rotate(&m0, &m2);
        StoreAll_23B4C0(&self->mtx, &m0, LoadQ_23B4C0(&self->pos), &m0.r[3]);
    }
    self->Apply();
    for (i = 0; i < self->an; i++)
        self->adata[i]->Reset();
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B4C0(void) {}
#undef cMatrix_Rotate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B4C0 */

/* merge_units: begin func_0023B7D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
/* cNIEventOBJ_HandleMessage (message handler): for play messages, start (kind 0:
 * finish flags on the rotation/switch tracks, forward to the children),
 * stop (kind 1: forward) or reset (kind 2: rewind the tracks, rebuild the
 * node matrix from the first position key and the start rotations like
 * cNIEventOBJ_SetEndState (NIEvent_23B450.c), reset the attached object, forward and
 * return 1); everything else goes to cNIEventBase_HandleMessage. Message layout
 * as in cNIEventBase_Stop (cNIEventBase_Stop.c). */
struct V4_B7D0 { float x, y, z, w;
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_B7D0 { V4_B7D0 r[4];
    M4_B7D0() {}
};
static inline float Rad_B7D0(float d) { return d * 0.017453292f; }
static inline __int128 LoadQ_B7D0(const V4_B7D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); return t; }
struct K64_B7D0 { float t; char pad4[0xC]; V4_B7D0 pos; char pad20[0x20]; };
struct Key_B7D0 { float t; float v; char pad8[8]; };
struct Rot_B7D0 { float val; int cap; int n; Key_B7D0* data; int pad10; int state; int t; unsigned char flag; char pad1D[3]; };
extern "C" { extern int D_004F7C28; extern char D_004DC2F0[]; }
struct Msg_B7D0;
extern "C" { void cMessage_ctor_cMessageNameR(Msg_B7D0* m, void* name); void cMessage_dtor(Msg_B7D0* m, int flags); }
struct Msg_B7D0 { void* vtable; char pad04[0x1C]; unsigned char b20; char pad21[3]; int kind; char pad28[8];
};
class Obj_B7D0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Enable(int on);
    virtual void Show(int on);
    char pad4[0x6C - 4];
    int f6C;
};
class Self_B7D0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual void Rewind(float t);
    char pad4[0x60 - 0x4];
    int mode;
    char pad64[0xA0 - 0x64];
    int an; void** adata;
    char padA8[0xB4 - 0xA8];
    K64_B7D0* d1;
    char padB8[0xC0 - 0xB8];
    int t1;
    char padC4[0xD8 - 0xC4];
    int t2;
    char padDC[0xE0 - 0xDC];
    V4_B7D0 pos;
    M4_B7D0 mtx;
    unsigned char b130;
    char pad131[0x140 - 0x131];
    Obj_B7D0* obj;
    Rot_B7D0 rx;
    Rot_B7D0 ry;
    Rot_B7D0 rz;
    char pad1A4[4];
    unsigned char b1A8;
    char pad1A9[3];
    int i1AC;
};
extern "C" {
int* cMessage_Name(void* ev);
void QueueMessage_cMessageR_cSystemP_int(Msg_B7D0* m, void* target, int a);
#if 0 /* merge_units */
float cVector_X_void(V4_B7D0* v);
#endif /* merge_units */
#define cVector_X_void(a0) (cVector_X_void((V4_23B4C0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float cVector_Y_void(V4_B7D0* v);
#endif /* merge_units */
#define cVector_Y_void(a0) (cVector_Y_void((V4_23B4C0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float cVector_Z_void(V4_B7D0* v);
#endif /* merge_units */
#define cVector_Z_void(a0) (cVector_Z_void((V4_23B4C0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetWithAxisAngle(M4_B7D0* m, float x, float y, float z, float a);
#endif /* merge_units */
#define cMatrix_SetWithAxisAngle(a0, a1, a2, a3, a4) (cMatrix_SetWithAxisAngle((M4_23B4C0 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_ctor_void(M4_B7D0* m);
#endif /* merge_units */
#define cMatrix_ctor_void(a0) (cMatrix_ctor_void((M4_23B4C0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_Rotate(M4_B7D0* a, M4_B7D0* b);
#endif /* merge_units */
#define cMatrix_Rotate(a0, a1) ((void)cMatrix_Rotate((V4 *)(a0), (V4 *)(a1))) /* merge_units */

int cNIEventBase_HandleMessage(Self_B7D0* self, Msg_B7D0* ev);
int cNIEventOBJ_HandleMessage(Self_B7D0* self, Msg_B7D0* ev);
}
static inline void VCopy_B7D0(V4_B7D0* d, const V4_B7D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void Cp_B7D0(void* d, const void* s) { __int128 t; asm volatile { .set reorder; lq t, 0(s); sq t, 0(d) } }
static inline void MakeRot_B7D0(M4_B7D0* m, const V4_B7D0& a, float ang) { cMatrix_SetWithAxisAngle(m, a.x, a.y, a.z, ang); }
static inline void Rewind_B7D0(Rot_B7D0* r) {
    r->t = 0;
    if (r->n > 0)
        r->val = r->data[0].v;
}

static inline void BuildRot_B7D0(Self_B7D0* o, M4_B7D0* pm)
{
    V4_B7D0 ax1;
    V4_B7D0 ax2;
    V4_B7D0 ax3;
    M4_B7D0 m1;
    M4_B7D0 m2;
    float ang; float bng; float cng;
    ang = Rad_B7D0(o->rx.val);
    ax1.Set(1.0f, 0.0f, 0.0f, 0.0f);
    cMatrix_SetWithAxisAngle(pm, cVector_X_void(&ax1), cVector_Y_void(&ax1), cVector_Z_void(&ax1), ang);
    bng = Rad_B7D0(o->ry.val);
    ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
    cMatrix_ctor_void(&m1);
    MakeRot_B7D0(&m1, ax2, bng);
    cMatrix_Rotate(pm, &m1);
    cng = Rad_B7D0(o->rz.val);
    ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
    cMatrix_ctor_void(&m2);
    MakeRot_B7D0(&m2, ax3, cng);
    cMatrix_Rotate(pm, &m2);
}

// 4x128-bit lq/sq matrix copy, interleaved as in retail (no C equivalent for the quadword pairing)
static inline void CopyM_B7D0(M4_B7D0* d, const M4_B7D0* s) { __int128 qa; __int128 qb; asm { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
extern "C" int cNIEventOBJ_HandleMessage(Self_B7D0* self, Msg_B7D0* ev)
{
    Msg_B7D0* e = ev;
    int i;
    Msg_B7D0* p;
    Msg_B7D0* q;
    int j;
    Self_B7D0* o = self;
    int t;
    t = *cMessage_Name(e);
    if (t == D_004F7C28) {
        switch (e->kind) {
        case 0:
            o->rx.flag = 1;
            o->ry.flag = 1;
            o->rz.flag = 1;
            o->b1A8 = 1;
            for (i = 0; i < o->an; i++) {
                Msg_B7D0 m;
                p = &m;
                cMessage_ctor_cMessageNameR(p, &D_004F7C28);
                p->vtable = D_004DC2F0;
                p->kind = 0;
                m.b20 = 1;
                QueueMessage_cMessageR_cSystemP_int(p, o->adata[i], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(p, 0);
            }
            break;
        case 1:
            for (i = 0; i < o->an; i++) {
                Msg_B7D0 m;
                p = &m;
                cMessage_ctor_cMessageNameR(p, &D_004F7C28);
                p->vtable = D_004DC2F0;
                p->kind = 1;
                m.b20 = 1;
                QueueMessage_cMessageR_cSystemP_int(p, o->adata[i], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(p, 0);
            }
            break;
        case 2: {
            M4_B7D0 m0;
            Rewind_B7D0(&o->rx);
            Rewind_B7D0(&o->ry);
            Rewind_B7D0(&o->rz);
            o->i1AC = 0x80000000;
            o->b1A8 = 0;
            o->t1 = 0;
            o->t2 = 0;
            Cp_B7D0(&o->pos, &o->d1[0].pos);
            BuildRot_B7D0(o, &m0);
            { V4_B7D0* pd = &m0.r[3]; __int128 t = LoadQ_B7D0(&o->pos); *(__int128*)pd = t; CopyM_B7D0(&o->mtx, &m0); }
            if (o->mode == 2 && o->obj) {
                o->obj->f6C = 0;
                o->obj->Show(1);
                o->obj->Enable(1);
            }
            o->Rewind(0.0f);
            o->b130 = 0;
            for (j = 0; j < o->an; j++) {
                Msg_B7D0 m;
                q = &m;
                cMessage_ctor_cMessageNameR(q, &D_004F7C28);
                q->vtable = D_004DC2F0;
                q->kind = 2;
                m.b20 = 1;
                QueueMessage_cMessageR_cSystemP_int(q, o->adata[j], 0);
                m.vtable = D_004DC2F0;
                cMessage_dtor(q, 0);
            }
            return 1;
        }
        }
    }
    return cNIEventBase_HandleMessage(o, e);
}
#undef cVector_X_void /* merge_units */
#undef cVector_Y_void /* merge_units */
#undef cVector_Z_void /* merge_units */
#undef cMatrix_SetWithAxisAngle /* merge_units */
#undef cMatrix_ctor_void /* merge_units */
#undef cMatrix_Rotate /* merge_units */
static inline void merge_flush_func_0023B7D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B7D0 */
