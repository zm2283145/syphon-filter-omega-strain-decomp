/*
 * SFOGame/Source/decals: 4 files, 00279CA0-0027A370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00279CA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x5C]; float t; } E279CA0;
typedef struct {
    E279CA0** items; int pad4; int cap; int padC; int count; int pad14;
    unsigned int head; int pad1C; int base;
} R279CA0;
extern void cDecal_ctor(E279CA0* e, int flags, int a, int b, float x, float y);
void cDecalMan_AddDecal(R279CA0* r, int a1, int a2, unsigned char a3, int t0, float f)
{
    unsigned int idx;
    unsigned int slot;
    E279CA0* e;
    int fl;
    idx = r->head++;
    slot = (idx + r->base) % r->cap;
    if (r->head == r->cap) {
        r->head = 0;
    }
    if (r->count < r->cap) {
        r->count++;
    } else {
        e = r->items[slot];
        if (e->t != -2.0f) {
            e->t = 0.0f;
        }
    }
    fl = a3 | 1;
    e = r->items[idx];
    if (e) {
        cDecal_ctor(e, fl, a1, t0, f, (float)a2);
    }
}
static inline void merge_flush_func_00279CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00279CA0 */

/* merge_units: begin func_00279D80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void operator_delete(void* p);
}
struct S_00279D80 { void** a; void** b; int na; int nb; };
static inline void Free_00279D80(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, "decals.cc", line); }
extern "C" S_00279D80* cDecalMan_dtor(S_00279D80* self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < self->na; i++) Free_00279D80(self->a[i], 0x87);
        { int j; for (j = 0; j < self->nb; j++) Free_00279D80(self->b[j], 0x89); }
        Free_00279D80(self->a, 0x8B);
        Free_00279D80(self->b, 0x8C);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00279D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00279D80 */

/* merge_units: begin func_0027A020 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Item_27A020 { int f0; char pad4[0x4C]; int f50; int f54; int f58; float f5C; };
struct Mgr_27A020 {
    Item_27A020** a; Item_27A020** b; int na; int nb; int f10; int f14; int f18; int f1C;
    int f20; int f24; char pad28[8]; char f30[1];
};
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void CreateSphereNormals(void* p, int n);
extern char D_004A9238[];
extern int D_00543798;
}
extern "C" Mgr_27A020* cDecalMan_ctor(Mgr_27A020* self, int na, int nb) {
    self->a = 0;
    self->b = 0;
    self->na = na;
    self->nb = nb;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    { Item_27A020** t; { int sz = self->na * 4; AllocGuard g; t = (Item_27A020**)cMemMan_Allocate(0, sz, D_004A9238, 0x74); } self->a = t; }
    { Item_27A020** t; { int sz = self->nb * 4; AllocGuard g; t = (Item_27A020**)cMemMan_Allocate(0, sz, D_004A9238, 0x75); } self->b = t; }
    {
        int i;
        for (i = 0; i < self->na; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)cMemMan_Allocate(0, 0x60, D_004A9238, 0x78); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->a[i] = p;
        }
    }
    {
        int i;
        for (i = 0; i < self->nb; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)cMemMan_Allocate(0, 0x60, D_004A9238, 0x7A); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->b[i] = p;
        }
    }
    self->f20 = (int)(0.1f * (float)self->na);
    self->f24 = (int)(0.1f * (float)self->nb);
    CreateSphereNormals(self->f30, 0x20);
    D_00543798 = self->nb;
    return self;
}
static inline void merge_flush_func_0027A020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A020 */

/* merge_units: begin func_0027A370 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* DecalMgr_AddBloodRecord: fill a blood decal record (position + direction), in the parent's local frame when attached */
struct M;
struct V;
static inline void AddV(V* d, V* a, V* b);
static inline void AddV2(V* d, V* a, V* b) { AddV(d, a, b); }
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator+(V o) const { V r; const V* tp = this; V* rp = &r; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V& operator*=(float k) { V* tp = this; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(tp), "f"(k) : "memory"); return *this; }
    V& operator+=(V o) { AddV2(this, this, &o); return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V Sub3(const V& o) const { V r; const V* op = &o; const V* tp = this; V* rp = &r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    void Set(V o) { *this = o; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V Sub2(const V& o) const { V r; const V* op = &o; V* rp = &r; const V* tp = this; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    // 128-bit lq/sq quadword copy idiom
    V& Asg(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    inline V& Xform(M* m);
} __attribute__((aligned(16)));

struct M {
    V r0, r1, r2, r3;
    M() {}
    // 128-bit lq/sq quadword copy idiom
    M& operator=(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    float* f() { return (float*)this; }
};

// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode vector op (COP2), not expressible in C
inline V& V::Xform(M* m) { Apply(this, m, this); return *this; }
static inline void UM(void* p) { void* q = p; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(q) : "memory"); }
struct Node_7A570 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; M xform; unsigned char dirty;
};
struct Obj_7A570 { char pad[0x50]; Node_7A570* node; };
struct F4_7A370 { float x, y, z, w; void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; } };
struct Rec_7A370 { int flags; char pad4[0xC]; V r0; F4_7A370 r1; V r2; V r3; float f50; int x54; Obj_7A570* parent; float f5C; };
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, M* s);
M* cMatrix_InvertRotTrans(M* m);
Rec_7A370* DecalMgr_AddBloodRecord(Rec_7A370* r, int flags, V* pos, F4_7A370* dir, float f, float g, Obj_7A570* parent);
}
static inline M* GetXform(Node_7A570* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline M* InvOf(M* out, Node_7A570* n) { M t; return cMatrix_ctor_cMatrixR(out, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, GetXform(n)))); }
static inline void Apply1(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V XF(const V& v, M* m) { V t = v; V* p = &t; Apply1(p, m); return *p; }
/* XF2: pass-through layer for the second transform (register order of that call site) */
static inline V XF3(const V& v, M* m) { V t = v; V* p = &t; Apply1(p, m); return *p; }
static inline V XF2(const V& v, M* m) { return XF3(v, m); }
/* pass-through layers: deeper inlines get lower stack slots */
static inline M* InvOf2(M* out, Node_7A570* n) { return InvOf(out, n); }
static inline M* InvOf3(M* out, Node_7A570* n) { return InvOf2(out, n); }
Rec_7A370* DecalMgr_AddBloodRecord(Rec_7A370* r, int flags, V* pos, F4_7A370* dir, float f, float g, Obj_7A570* parent)
{
    r->flags = flags;
    r->f50 = f;
    r->x54 = (int)g;
    r->parent = parent;
    r->f5C = -1.0f;
    if ((r->flags & 2) && r->parent) {
        Node_7A570* n = r->parent->node;
        if (n) {
            M inv;
            InvOf3(&inv, n);
            V lp = XF(*pos, &inv);
            V ld = XF2(*(V*)dir, &inv);
            UM(&r->r0);
            r->r3 = lp;
            r->r1.Set(ld.x, ld.y, ld.z, ld.w);
        } else {
            UM(&r->r0);
            r->r3 = *pos;
            r->r1.Set(dir->x, dir->y, dir->z, dir->w);
        }
    }
    return r;
}
static inline void merge_flush_func_0027A370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A370 */
