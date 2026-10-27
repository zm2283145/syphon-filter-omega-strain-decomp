/*
 * SFOGame/Source/NIEvent: 5 files, 00239DF0-0023A2D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00239DF0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#pragma optimize_for_size on
struct Key_239DF0 { float a; float t; float c; float d; };
struct Vec_239DF0 {
    int capacity; int count; Key_239DF0* data;
};
struct Track_239DF0 {
    float cur;
    Vec_239DF0 keys;
    int pad10;
    int w14;
    int w18;
    unsigned char b1C;
};
struct Reader_239DF0 { int version; int size; unsigned int base; char* cur; };
static inline float RdF_239DF0(Reader_239DF0* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline int RdI_239DF0(Reader_239DF0* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline Key_239DF0* Zero_239DF0(void* d0, int n0) { void* dst = d0; int n = n0; Key_239DF0* r;
    asm {
        beqz dst, done
        move r, dst
    loop:
        sb $zero, 0(dst)
        addiu n, n, -1
        addiu dst, dst, 1
        bnez n, loop
    done:
    }
    return r;
}
extern "C" void std_vector_imp_FloatKey_resize(Vec_239DF0* v, unsigned int n, const Key_239DF0* value);
extern "C" void cNIEventFloatTrack_Init_cPopulationR(Track_239DF0* self, Reader_239DF0* r)
{
    Key_239DF0 k1;
    Key_239DF0 k0;
    int n = RdI_239DF0(r);
    int i;
    if (n)
        self->w14 = (int)(RdF_239DF0(r) - 1.0f);
    {
        Key_239DF0* p1 = Zero_239DF0(&k1, 16);
        Key_239DF0* p0 = Zero_239DF0(&k0, 16);
        std_vector_imp_FloatKey_resize(&self->keys, 0, p0);
        std_vector_imp_FloatKey_resize(&self->keys, n, p1);
    }
    i = 0;
    if (0 < n) do {
        self->keys.data[i].a = RdF_239DF0(r);
        self->keys.data[i].t = RdF_239DF0(r);
        self->keys.data[i].c = *(float*)r->cur;
        r->cur += 4;
        self->keys.data[i].d = *(float*)r->cur;
        r->cur += 4;
    } while (++i < n);
    self->b1C = 0;
    self->w18 = 0;
    if (self->keys.count > 0)
        self->cur = self->keys.data[0].t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239DF0 */

/* merge_units: begin func_00239FA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Tgt00239FA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void apply();
    char pad[0x34];
    int value;
};
struct Ev00239FA0 {
    char pad00[0x38];
    int value;
    char pad3C[0xDC - 0x3C];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt00239FA0* target;
};
extern "C" void cNIEventOBJ_Render(Ev00239FA0* self)
{
    if (self->enabled) {
        self->target->value = self->value;
        self->target->apply();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239FA0 */

/* merge_units: begin func_00239FF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { Mtx* d = this; const Mtx* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
struct Sub {
    VPAD1(a)
    virtual void SetMtx(Mtx* m);
    VPAD16(b) VPAD2(c)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
struct Box { V mn, mx; };
struct Obj {
    VPAD32(a)
    virtual Box* GetBox();
    char pad4[0x4C];
    Sub* sub;
};
static inline const Mtx& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
// abs.s: no C equivalent
static inline float Fabs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void MulM(V* v, Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }

extern "C" int cNIEventOBJ_GetBeamExtents(Obj* o, V* mn, V* mx)
{
    V c;
    V e;
    Box* b = o->GetBox();
    if (!b) return 0;
    *mn = b->mn;
    *mx = b->mx;
    Mtx m = SubMtx(o->sub);
    float ax = Fabs(mx->x - mn->x);
    float ay = Fabs(mx->y - mn->y);
    float az = Fabs(mx->z - mn->z);
    c.w = 1.0f;
    c.x = mn->x + (mx->x - mn->x) / 2.0f;
    c.y = mn->y + (mx->y - mn->y) / 2.0f;
    c.z = mn->z + (mx->z - mn->z) / 2.0f;
    e = c;
    if (!(ax < ay) && !(ax < az)) {
        c.x = mn->x;
        e.x = mx->x;
    } else if (!(ay < ax) && !(ay < az)) {
        c.y = mn->y;
        e.y = mx->y;
    } else {
        c.z = mn->z;
        e.z = mx->z;
    }
    *mn = c;
    *mx = e;
    MulM(mn, &m);
    MulM(mx, &m);
    return 1;
}
static inline void merge_flush_func_00239FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00239FF0 */

/* merge_units: begin func_0023A250 */
#pragma push /* merge_units */
#pragma cplusplus on

class Tgt0023A250 {
public:
    VPAD32(a)
    virtual int run();
};
struct Ev0023A250 {
    char pad00[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0xDC - 0x2F];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt0023A250* target;
};
extern "C" int cNIEventOBJ_GetBBox(Ev0023A250* self)
{
    Tgt0023A250* t;
    return (self->enabled && (t = self->target) != 0 && !(self->b2D == 0) && self->b2C && !self->b2E)
        ? t->run() : 0;
}
static inline void merge_flush_func_0023A250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A250 */

/* merge_units: begin func_0023A2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
/* cNIEventOBJ_ForceMatUpdate (update): updates the event node, then drives the attached
 * object from the owner's matrix: for mode 5 with rows 1 and 2 swapped and
 * the new row 1 negated (Y/Z swap), otherwise through the play or idle
 * matrix slot depending on whether the event is playing; finally pokes every
 * child element of the two attach types. Types as in cNIEventOBJ_SetEndState
 * (NIEvent_23B450.c) and cNIEventLight_ProcessNextFrame. */
#pragma always_inline on
#pragma inline_depth(8)
struct V4_A2D0 { float x, y, z, w; } __attribute__((aligned(16)));
struct M4_A2D0 { V4_A2D0 r[4]; };
class Owner_A2D0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char p4[0x10 - 4];
    M4_A2D0 mtx;
    unsigned char dirty;
};
class Obj_A2D0 {
public:
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetMatrix(M4_A2D0* m);
    VPAD4(d) VPAD1(e)
    virtual void SetIdleMatrix(M4_A2D0* m);
    char p4[0x50 - 4];
    void* model;
};
class Elem_A2D0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Attach();
    char p4[0x4C - 4];
    int type;
};
struct PtrVec_A2D0 { int cap; int n; Elem_A2D0** data; };
class Ev_A2D0 {
public:
    VPAD1(a)
    char p4[0x50 - 4];
    Owner_A2D0* owner;
    char p54[0x60 - 0x54];
    int mode;
    char p64[0x9C - 0x64];
    PtrVec_A2D0 elems;
    char pA8[0x130 - 0xA8];
    unsigned char playing;
    char p131[0x140 - 0x131];
    Obj_A2D0* obj;
};
extern "C" {
extern int D_004F7C60;
extern int D_004F7C98;
void cNIEventBase_ForceMatUpdate(Ev_A2D0* self);
Elem_A2D0** std_vector_cNIEventBasePtr_opIndex(PtrVec_A2D0* v, int i);
void cMatrix_SetXAxis(M4_A2D0* m, V4_A2D0* v);
void cMatrix_SetYAxis(M4_A2D0* m, V4_A2D0* v);
void cMatrix_SetZAxis(M4_A2D0* m, V4_A2D0* v);
void cNIEventOBJ_ForceMatUpdate(Ev_A2D0* self);
}
static inline void GQR(void* dd, void* ss) { void* s = ss; void* d = dd; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void VCopy(V4_A2D0* d, const V4_A2D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline Elem_A2D0* At(PtrVec_A2D0* v, int i) { return *std_vector_cNIEventBasePtr_opIndex(v, i); }
static inline bool Is(int k, Elem_A2D0* e) { return e->type == k; }
static inline Owner_A2D0* SyncedOwner(Ev_A2D0* self) { Owner_A2D0* o = self->owner; if (o->dirty) o->Sync(); return o; }

extern "C" void cNIEventOBJ_ForceMatUpdate(Ev_A2D0* self)
{
    int i;
    cNIEventBase_ForceMatUpdate(self);
    if (self->obj && self->obj->model) {
        if (self->mode != 5) {
            if (self->playing) {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetMatrix(&o->mtx);
            } else {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetIdleMatrix(&o->mtx);
            }
        } else {
            Owner_A2D0* o = SyncedOwner(self);
            M4_A2D0 m;
            V4_A2D0 r0;
            V4_A2D0 r1;
            V4_A2D0 r2;
            GQR(&m, &o->mtx);
            VCopy(&r0, &m.r[0]);
            VCopy(&r1, &m.r[1]);
            VCopy(&r2, &m.r[2]);
            r2.x = -r2.x;
            r2.y = -r2.y;
            r2.z = -r2.z;
            cMatrix_SetXAxis(&m, &r0);
            cMatrix_SetYAxis(&m, &r2);
            cMatrix_SetZAxis(&m, &r1);
            self->obj->SetMatrix(&m);
        }
    }
    for (i = 0; i < self->elems.n; i++) {
        if (Is(D_004F7C60, At(&self->elems, i)))
            self->elems.data[i]->Attach();
        else if (Is(D_004F7C98, At(&self->elems, i)))
            self->elems.data[i]->Attach();
    }
}
static inline void merge_flush_func_0023A2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A2D0 */
