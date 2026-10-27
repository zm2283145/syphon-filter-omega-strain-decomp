/*
 * Libs/SFOLib/Source/lights: 6 files, 003718B0-00371CF0
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
extern void cVU1Model_UpdateLighting(void* a, int b, int c);
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
