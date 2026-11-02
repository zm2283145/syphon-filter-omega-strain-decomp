/*
 * Libs/SFOLib/Source/lights: 10 files, 003718B0-00372AC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003718B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

typedef struct { int pad0; void* light; char pad8[24]; } LE18B0;
typedef struct { char pad0[0x4C]; int count; char pad50[0x10]; LE18B0 ents[1]; } LM18B0;
typedef struct { char pad[0x60]; LE18B0 e; } LR18B0;

struct L18B0 {
    char pad0[4];
    void* vt;
    int x8;
    char padC[0x12];
    unsigned char type;
};

extern "C" {
extern char D_004DF700[];
extern char D_004D9240[];
extern char D_004D9280[];
extern unsigned char g_LevelLightsDirty;
extern LM18B0 g_LightMgr;
void SyncDCache(LE18B0*, LE18B0*);
}

static inline void QMove18B0(void* d, void* s, int n) {
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

struct VB18B0 { char k; char f; };
struct VI18B0 : VB18B0 { VPAD8(a) VPAD2(b) virtual void Disable(); };

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
static inline void Remove18B0(LM18B0* m, L18B0* l) {
    int i;
    switch (l->type) {
    case 1:
        break;
    case 2:
        break;
    case 4:
        l->x8 = -1;
        break;
    case 0x10:
        break;
    }
    for (i = 0; i < m->count; i++) {
        if (*(L18B0**)((int)&m->ents[0].light + (i << 5)) == l) {
            m->count = m->count - 1;
            QMove18B0(&((LR18B0*)((int)m + (i << 5)))->e, &m->ents[i + 1], (m->count - i) * 2);
            SyncDCache(m->ents, &m->ents[m->count]);
            return;
        }
    }
}

extern "C" L18B0* cSceneLight_dtor(L18B0* p, short flag)
{
    if (p) {
        p->vt = D_004DF700;
        if (p) {
            p->vt = D_004D9240;
            p->x8 = -1;
            ((VI18B0*)p)->Disable();
            g_LevelLightsDirty = 1;
            if (p) p->vt = D_004D9280;
        }
        if (flag > 0) Remove18B0(&g_LightMgr, p);
    }
    return p;
}
static inline void merge_flush_func_003718B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003718B0 */

/* merge_units: begin func_00371A60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* obj; int arg; } E2Slot;
typedef struct {
    char pad0[0x1C];
    unsigned char dirty;
    char pad1[0x58 - 0x1D];
    unsigned char active;
    char pad2[3];
    int count;
    E2Slot slots[16];
} E2Group;
extern void cVU1Model_UpdateLighting(void*, int, int);
void cSceneLight_Deactivate(E2Group* g) {
    int i;
    if (g->active && g->count) {
        for (i = 0; i < 16; i++) {
            E2Slot* s = &g->slots[i];
            if (s->obj) cVU1Model_UpdateLighting(s->obj, s->arg, 0);
        }
        g->active = 0;
    }
    if (g->dirty) {
        g->dirty = 0;
        g_LevelLightsDirty = 1;
    }
}
static inline void merge_flush_func_00371A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371A60 */

/* merge_units: begin func_00371B00 */
#pragma push /* merge_units */
typedef struct { void* a; int b; } E4Slot;
typedef struct {
    char pad0[0x1C];
    unsigned char b1C;
    char pad1D[0x58 - 0x1D];
    unsigned char b58;
    char pad59[3];
    int n5C;
    E4Slot slots[16];
} E4Obj;
#if 0 /* merge_units */
extern void cVU1Model_UpdateLighting(void* a, int b, int c);
#endif /* merge_units */
#define cVU1Model_UpdateLighting(a0, a1, a2) (cVU1Model_UpdateLighting((a0), (a1), (a2))) /* merge_units */

void cSceneLight_Activate(E4Obj* o)
{
    int i;
    if (!o->b58 && o->n5C) {
        for (i = 0; i < 16; i++) {
            E4Slot* p = &o->slots[i]; if (p->a) cVU1Model_UpdateLighting(p->a, p->b, 1);
        }
        o->b58 = 1;
    }
    if (!o->b1C) {
        o->b1C = 1;
        g_LevelLightsDirty = 1;
    }
}
#undef cVU1Model_UpdateLighting /* merge_units */
static inline void merge_flush_func_00371B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371B00 */

/* merge_units: begin func_00371B90 */
#pragma push /* merge_units */
typedef struct { int id; int val; } LmSlot;
typedef struct {
    char pad0[8];
    int key;
    char padc[0x5C - 0xC];
    int count;
    LmSlot slots[16];
    char pade0[0xE0 - 0xE0];
} LmGroup;
typedef struct { char pad0[0xC]; LmGroup* groups; char pad10[0xC]; int numGroups; } LightMgr;
void cLightMan_RemoveSceneLightRef(LightMgr* mgr, int key, int id)
{
    LmGroup* g = 0;
    int i;
    int j;
    for (i = 0; i < mgr->numGroups; i++) {
        if (key == mgr->groups[i].key) {
            g = &mgr->groups[i];
            break;
        }
    }
    if (!g) return;
    for (j = 0; j < 16; j++) {
        if (g->slots[j].id == id) {
            /* unsigned index keeps the stores out of strength reduction */
            g->slots[(unsigned)j].id = 0;
            g->slots[(unsigned)j].val = -1;
            g->count--;
        }
    }
}
static inline void merge_flush_func_00371B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371B90 */

/* merge_units: begin func_00371C30 */
#pragma push /* merge_units */
void cLightMan_AddSceneLightRef(LightMgr* mgr, int key, int id, int val)
{
    LmGroup* g = 0;
    int i;
    int free;
    int j;
    for (i = 0; i < mgr->numGroups; i++) {
        if (key == mgr->groups[i].key) {
            g = &mgr->groups[i];
            break;
        }
    }
    free = -1;
    if (!g) return;
    for (j = 0; j < 16; j++) {
        if (g->slots[j].id == id) return;
        if (g->slots[j].id == 0) {
            free = j;
            break;
        }
    }
    if (free >= 0) {
        g->slots[free].id = id;
        g->slots[free].val = val;
        g->count++;
    }
}
static inline void merge_flush_func_00371C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371C30 */

/* merge_units: begin func_00371CF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { float m[4][4]; } __attribute__((aligned(16)));
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
}
static inline V MulV(const M& m, V v) {
    const M* pm = &m; V* pv = &v;
    __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(pv), "r"(pm) : "memory");
    return *pv;
}
static inline void Inverse(M* out, const M* m) { M a; cMatrix_ctor_cMatrixR(out, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, m))); }
struct Src {
    int f0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual float Radius();
    char pad8[8];
    float f10;
    char pad14[0xC];
    float f20, f24, f28;
    char pad2C[4];
    V v30;
};
struct Ent { V pos; float sx, sy, sz, r; };
struct Sys {
    char pad[0x2130];
    int count;
    Src* src[7];
    Ent ents[6];
    int f2210;
};
static inline void Inverse2(M* out, const M* m) { Inverse(out, m); }
static inline V XP2(const M* m, const V& p) { M inv; Inverse2(&inv, m); return MulV(inv, p); }
static inline void CopyTo(const V* s, V* d) { void* xx = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cLightMan_VU1PreparePoint(Sys* s, const M* m)
{
    int i;
    for (i = 0; i < s->count; i++) {
        Src* o = s->src[i];
        s->ents[i].sx = 128.0f * o->f20;
        s->ents[i].sy = 128.0f * o->f24;
        s->ents[i].sz = 128.0f * o->f28;
        s->ents[i].r = o->f10;
        s->ents[i].pos = o->v30;
        if (m) {
            { V r = XP2(m, s->ents[i].pos); CopyTo(&r, &s->ents[i].pos); }
        }
        s->ents[i].pos.w = o->Radius();
    }
    s->f2210 = s->count;
}
static inline void merge_flush_func_00371CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371CF0 */

/* merge_units: begin func_00371E70 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_00371E70 {
    float x, y, z, w;
    V_00371E70() {}
    V_00371E70(const V_00371E70& o) { V_00371E70* d = this; const V_00371E70* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V_00371E70& operator=(const V_00371E70& o) { void* xx = this; const V_00371E70* s = &o; V_00371E70* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
};
static inline void XformInPlace(V_00371E70* v, const M* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
static inline V_00371E70 Xform(V_00371E70 v, const M& m) { XformInPlace(&v, &m); return v; }
static inline void QMoveA(void* s, int n, void* d) {
    __int128 t; int nn = n; void* dd = d; void* ss = s; 
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
static inline void QMoveB(void* d, int n, void* s) {
    int nn = n; __int128 t; void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
struct LData { char pad[0x2800]; V_00371E70 lights[4]; V_00371E70 x2840[4]; };
struct LMgr {
    char pad0[0x54];
    LData* data;
    char pad58[0x2070 - 0x58];
    V_00371E70 x2070[4];
    float x20B0[4][4];
    V_00371E70 x20F0[4];
};
extern "C" {
}
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
static inline M* InvCopy(M* b, M* m) { M a; return cMatrix_ctor_cMatrixR(b, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, m))); }
extern "C" void cLightMan_VU1PrepareParallel(LMgr* self, M* m)
{
    V_00371E70 rows[4];
    if (m) {
        M b;
        InvCopy(&b, m);
        for (int i = 0; i < 4; i++) {
            rows[i] = Xform(self->data->lights[i], b);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            rows[i] = self->data->lights[i];
        }
    }
    QMoveA(self->data->lights, 4, self->x2070);
    QMoveB(self->x20B0, 4, rows);
    {
        float (*t)[4] = self->x20B0;
        float f;
        f = t[0][1]; t[0][1] = t[1][0]; t[1][0] = f;
        f = t[0][2]; t[0][2] = t[2][0]; t[2][0] = f;
        f = t[1][2]; t[1][2] = t[2][1]; t[2][1] = f;
        f = t[0][3]; t[0][3] = t[3][0]; t[3][0] = f;
        f = t[1][3]; t[1][3] = t[3][1]; t[3][1] = f;
        f = t[2][3]; t[2][3] = t[3][2]; t[3][2] = f;
    }
    QMoveA(self->data->x2840, 4, self->x20F0);
    self->x20F0[0].x *= 128.0f; self->x20F0[0].y *= 128.0f; self->x20F0[0].z *= 128.0f;
    self->x20F0[1].x *= 128.0f; self->x20F0[1].y *= 128.0f; self->x20F0[1].z *= 128.0f;
    self->x20F0[2].x *= 128.0f; self->x20F0[2].y *= 128.0f; self->x20F0[2].z *= 128.0f;
    self->x20F0[3].x *= 128.0f; self->x20F0[3].y *= 128.0f; self->x20F0[3].z *= 128.0f;
}
#pragma pop
static inline void merge_flush_func_00371E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00371E70 */

/* merge_units: begin func_00372120 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
struct V_00372120 {
    float x, y, z, w;
    V_00372120() {}
    V_00372120(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00372120(float a, float b, float c) { x = a; y = b; z = c; w = 0.0f; }
    V_00372120(const V_00372120& o) { void* xx = this; Q1(this, &o); }
    V_00372120& operator=(const V_00372120& o) { void* xx = this; Q1(this, &o); return *this; }
    V_00372120& operator+=(const V_00372120& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    V_00372120& operator*=(float s) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(this), "f"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct C {
    float r, g, b, a;
    C() {}
    C(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; }
};
struct Light {
    char pad[0x1D]; unsigned char b1D; unsigned char b1E; char pad1F;
    float f20, f24, f28; char pad2C[4];
    V_00372120 v30; V_00372120 v40;
};
struct Amb { char pad[0x1C]; unsigned char b1C; char pad1D[3]; float f20, f24, f28; char pad2C[0x40 - 0x2C]; };
struct Ent_00372120 { Light* l; int x; };
struct Out { char pad[0x2000]; Ent_00372120 ents[0x100]; V_00372120 dirs[4]; C cols[4]; };
struct Ctx {
    Amb* amb; char pad4[0xC]; int nAmb; char pad14[0xC];
    V_00372120 pos; char pad30[0x43 - 0x30]; unsigned char b43; char pad44[4];
    int n48; int n4C; int n50; Out* out;
    char pad58[0x2060 - 0x58]; V_00372120 v2060;
    char pad2070[0x2130 - 0x2070]; int n2130; Light* lights[6];
    char pad214C[0x2220 - 0x214C]; unsigned char b2220; unsigned char b2221; char pad2222[0xE];
    V_00372120 v2230; V_00372120 v2240;
};
extern "C" {
#if 0 /* merge_units */
unsigned char func_00372B30(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
signed char func_00372B30(Obj372AC0* self); /* merge_units */
#define func_00372B30(a0) ((unsigned char)func_00372B30((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_00372120* cParallelLight_GetDirection(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
void* cParallelLight_GetDirection(Obj372AC0* self); /* merge_units */
#define cParallelLight_GetDirection(a0) ((V_00372120 *)cParallelLight_GetDirection((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_00372120* cLightSrc_GetPosition(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
void* cLightSrc_GetPosition(Obj372AC0* self); /* merge_units */
#define cLightSrc_GetPosition(a0) ((V_00372120 *)cLightSrc_GetPosition((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float func_00372B00(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
float func_00372B00(Obj372AC0* self); /* merge_units */
#define func_00372B00(a0) (func_00372B00((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float func_00372AF0(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
float func_00372AF0(Obj372AC0* self); /* merge_units */
#define func_00372AF0(a0) (func_00372AF0((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float func_00372AE0(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
float func_00372AE0(Obj372AC0* self); /* merge_units */
#define func_00372AE0(a0) (func_00372AE0((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_00372120* cSceneLight_GetDirection(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
void* cSceneLight_GetDirection(Obj372AC0* self); /* merge_units */
#define cSceneLight_GetDirection(a0) ((V_00372120 *)cSceneLight_GetDirection((Obj372AC0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
float cSceneLight_GetFalloffAngleCos(Light* l);
#endif /* merge_units */
struct Obj372AC0; /* merge_units */
float cSceneLight_GetFalloffAngleCos(Obj372AC0* self); /* merge_units */
#define cSceneLight_GetFalloffAngleCos(a0) (cSceneLight_GetFalloffAngleCos((Obj372AC0 *)(a0))) /* merge_units */

void cVector_opAssign(V_00372120* d, const V_00372120* s);
void cVector_opSub(V_00372120* o, const V_00372120* a, const V_00372120* b);
float cVector_GetLength(const V_00372120* v);
float cVector_Dot(const V_00372120* a, const V_00372120* b);
V_00372120* cVector_ctor_void(V_00372120* v);
float MAX(float a, float b);
float Math_MinF(float a, float b);
}
static inline float Falloff(Light* l, float len)
{
    float a = MAX(0.0f, len - func_00372B00(l));
    float r = func_00372AF0(l) - func_00372B00(l);
    if (a < r) return 1.0f - a / r;
    return 0.0f;
}
static inline float Intensity(Light* l, Ctx* c, V_00372120* d)
{
    float k = 1.0f;
    switch (func_00372B30(l)) {
    case 2:
        if (d) cVector_opAssign(d, cParallelLight_GetDirection(l));
        break;
    case 4: {
        V_00372120 t;
        cVector_opSub(&t, cLightSrc_GetPosition(l), &c->pos);
        k = cVector_GetLength(&t);
        if (d) {
            d->x = t.x / k;
            d->y = t.y / k;
            d->z = t.z / k;
            d->w = 0.0f;
        }
        k = Falloff(l, k);
        break;
    }
    case 0x10: {
        V_00372120 t;
        cVector_opSub(&t, cLightSrc_GetPosition(l), &c->pos);
        float len = cVector_GetLength(&t);
        V_00372120 n;
        cVector_ctor_void(&n);
        n.w = 0.0f;
        n.x = t.x / len;
        n.y = t.y / len;
        n.z = t.z / len;
        if (d) cVector_opAssign(d, &n);
        k = Falloff(l, len);
        if (func_00372AE0(l) != 1.0f) {
            float dot = cVector_Dot(cSceneLight_GetDirection(l), &n);
            float lo = cSceneLight_GetFalloffAngleCos(l);
            if (!(dot <= lo)) {
                float hi = func_00372AE0(l);
                if (dot < hi)
                {
                    float a = 1.0f - dot;
                    float e = 1.0f - lo;
                    float b = 1.0f - hi;
                    k *= 1.0f - (a - b) / (e - b);
                }
            } else
                k = 0.0f;
        }
        break;
    }
    }
    k = MAX(k, 0.0f);
    k = Math_MinF(k, 1.0f);
    return k;
}
extern "C" void cLightMan_UpdateSources(Ctx* c, unsigned int mask, unsigned int flags)
{
    if (flags & 2) c->n48 = 0;
    if (flags & 4) c->n2130 = 0;
    c->b2221 = 0;
    if (flags & 1) __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&c->v2060) : "memory");
    int n = 0;
    for (int i = 0; i < c->n50; i++) {
        Light* l = c->out->ents[i].l;
        if (!(mask & l->b1E)) continue;
        bool added = 0;
        if ((flags & 2) && c->n48 < 4) {
            V_00372120* d = &c->out->dirs[c->n48];
            float k = Intensity(l, c, d);
            C* col = &c->out->cols[c->n48];
            col->r = k * l->f20;
            col->g = k * l->f24;
            col->b = k * l->f28;
            col->a = 0.0f;
            added = 1;
            if (c->b2220 && !c->b2221 && (l->b1D & 0x20) > 0 && l->b1E == 2) {
                c->b2221 = 1;
                c->v2240 = l->v40;
                c->v2230 = l->v30;
            }
            c->n48++;
        }
        if ((flags & 4) && c->n2130 < 6)
            c->lights[c->n2130++] = l;
        if ((flags & 1) && c->b43 && n < 4) {
            if (added) {
                C* col = &c->out->cols[c->n48 - 1];
                c->v2060.x += col->r;
                c->v2060.y += col->g;
                c->v2060.z += col->b;
            } else {
                float k = Intensity(l, c, 0);
                c->v2060.x += k * l->f20;
                c->v2060.y += k * l->f24;
                c->v2060.z += k * l->f28;
            }
            n++;
        }
    }
    if (flags & 2) {
        for (int j = c->n48; j < 4; j++) {
            c->out->dirs[c->n48] = V_00372120(0.0f, 0.0f, 0.0f, 0.0f);
            c->out->cols[c->n48] = C(0.0f, 0.0f, 0.0f, 0.0f);
            c->n48++;
        }
    }
    if (flags & 1) {
        if (c->b43) {
            c->v2060 *= 1.0f / 6.0f;
        } else {
            for (int j = 0; j < c->nAmb; j++) {
                Amb* a = &c->amb[j];
                if (a->b1C) c->v2060 += V_00372120(a->f20, a->f24, a->f28);
            }
        }
        float s = 128.0f;
        V_00372120* a = &c->v2060;
        *a *= s;
        c->v2060.w = s;
    }
}
#undef func_00372B30 /* merge_units */
#undef cParallelLight_GetDirection /* merge_units */
#undef cLightSrc_GetPosition /* merge_units */
#undef func_00372B00 /* merge_units */
#undef func_00372AF0 /* merge_units */
#undef func_00372AE0 /* merge_units */
#undef cSceneLight_GetDirection /* merge_units */
#undef cSceneLight_GetFalloffAngleCos /* merge_units */
static inline void merge_flush_func_00372120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372120 */

/* merge_units: begin func_00372AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Field accessors of Obj372AC0.
 */

#include "loose03_types.h"

float cSceneLight_GetFalloffAngleCos(Obj372AC0* self) {
    return self->unk50;
}

void* cSceneLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

float func_00372AE0(Obj372AC0* self) {
    return self->unk54;
}

float func_00372AF0(Obj372AC0* self) {
    return self->unk14;
}

float func_00372B00(Obj372AC0* self) {
    return self->unk10;
}

void* cLightSrc_GetPosition(Obj372AC0* self) {
    return self->unk30;
}

void* cParallelLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

signed char func_00372B30(Obj372AC0* self) {
    return self->unk1E;
}
static inline void merge_flush_func_00372AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372AC0 */

/* merge_units: begin func_00372B40 */
#pragma push /* merge_units */
typedef struct { unsigned char m; unsigned char t; unsigned char f; unsigned char p3; int v; char pad[0x18]; } Light_00372B40;
typedef struct { int v; int z; } Cor;
typedef struct { Light_00372B40 l[256]; Cor c[1]; } Big;
typedef struct { char pad[0x4C]; int n; int nc; char* buf; char pad58[8]; char d[1]; } LightMgr_00372B40;
static inline void FASTDMA_ToSPR(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void FASTDMA_Wait_ToSPR(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
void cLightMan_AquireSourcesByProperty(LightMgr_00372B40* m, int a, int b, int c)
{
    int i;
    Light_00372B40* l;
    FASTDMA_ToSPR((int)m->buf, (int)m->d, m->n * 2);
    FASTDMA_Wait_ToSPR();
    m->nc = 0;
    for (i = 0; i < m->n; i++) {
        l = (Light_00372B40*)(m->buf + i * 32);
        if (!(l->m & a)) continue;
        if (b != 0xFF && !(l->t & b)) continue;
        if (!(l->f & c)) continue;
        ((Cor*)(m->buf + 0x2000))[m->nc].z = 0;
        ((Cor*)(m->buf + 0x2000))[m->nc].v = l->v;
        m->nc++;
    }
}
static inline void merge_flush_func_00372B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372B40 */
