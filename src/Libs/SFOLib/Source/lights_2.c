/*
 * Libs/SFOLib/Source/lights: 6 files, 00372C50-003730F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00372C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* cLightMan_AquireShadowSources: rebuild the point/spot light candidates around pos (TestPointSpot,
 * sorted by CompareSources) and hand the strongest ones to the shadow system:
 * directional lights as a reversed direction, the others as a position weighted by
 * their intensity at pos. Intensity is cLightMan_UpdateSources' (cLightMan_UpdateSources.c). */
/* quad copy as lq/sq (C struct copies go through FPRs) */
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    /* the unused xx reproduces retail's dead address set-up */
    V(const V& o) { void* xx = this; Q1(this, &o); }
    V& operator=(const V& o) { void* xx = this; Q1(this, &o); return *this; }
} __attribute__((aligned(16)));
/* VU0 negate: ACC = 0, vf1 = ACC - vf1 * 1 */
static inline V operator-(const V& a) { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%1)" : : "r"(&a), "r"(&r) : "memory"); return r; }
struct Light {
    char pad[0xC]; float scale; char pad10[0xE]; unsigned char type; char pad1F;
    float f20, f24, f28; char pad2C[4];
    V pos; V dir;
};
struct Entry { unsigned char flags; char pad1[0x1F]; };
struct Cand { Light* l; float key; };
struct Table { Entry entries[0x100]; Cand cand[1]; };
struct Mgr {
    char pad0[0x14]; int x14; int x18; int x1C;
    char pad20[0x4C - 0x20]; int count; int candCount; Table* table;
    char pad58[8]; char slots[0x10];
};
extern "C" {
extern char D_00543790[];
extern int D_00543794;
unsigned char func_00372B30(Light* l);
V* cParallelLight_GetDirection(Light* l);
V* cLightSrc_GetPosition(Light* l);
float func_00372B00(Light* l);
float func_00372AF0(Light* l);
#if 0 /* merge_units */
float func_00372AE0(Light* l);
#endif /* merge_units */
float func_00372AE0(void* light); /* merge_units */
#define func_00372AE0(a0) (func_00372AE0((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V* cSceneLight_GetDirection(Light* l);
#endif /* merge_units */
void* cSceneLight_GetDirection(void*); /* merge_units */
#define cSceneLight_GetDirection(a0) ((V *)cSceneLight_GetDirection((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
float cSceneLight_GetFalloffAngleCos(Light* l);
#endif /* merge_units */
float cSceneLight_GetFalloffAngleCos(void* light); /* merge_units */
#define cSceneLight_GetFalloffAngleCos(a0) (cSceneLight_GetFalloffAngleCos((void *)(a0))) /* merge_units */

void cVector_opAssign(V* d, const V* s);
#if 0 /* merge_units */
void cVector_opSub(V* o, const V* a, const V* b);
#endif /* merge_units */
void cVector_opSub(void*, void*, void*); /* merge_units */
#define cVector_opSub(a0, a1, a2) (cVector_opSub((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
float cVector_GetLength(const V* v);
#endif /* merge_units */
float cVector_GetLength(void*); /* merge_units */
#define cVector_GetLength(a0) (cVector_GetLength((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
float cVector_Dot(const V* a, const V* b);
#endif /* merge_units */
float cVector_Dot(void*, void*); /* merge_units */
#define cVector_Dot(a0, a1) (cVector_Dot((void *)(a0), (void *)(a1))) /* merge_units */

V* cVector_ctor_void(V* v);
float MAX(float a, float b);
float Math_MinF(float a, float b);
#if 0 /* merge_units */
void FASTDMA_ToSPR(Table* t, void* slots, int n);
#endif /* merge_units */
void FASTDMA_ToSPR(int sadr, int madr, int qwc); /* merge_units */
#define FASTDMA_ToSPR(a0, a1, a2) (FASTDMA_ToSPR((int)(a0), (int)(a1), (a2))) /* merge_units */

void FASTDMA_Wait_ToSPR(void);
#if 0 /* merge_units */
void cLightMan_AddLightScore(Mgr* m, Entry* e, V* pos);
#endif /* merge_units */
struct Pt1LcGather; /* merge_units */
struct Pt1LcEntry; /* merge_units */
struct Pt1LcVec; /* merge_units */
void cLightMan_AddLightScore(Pt1LcGather* g, Pt1LcEntry* e, Pt1LcVec* pos); /* merge_units */
#define cLightMan_AddLightScore(a0, a1, a2) (cLightMan_AddLightScore((Pt1LcGather *)(a0), (Pt1LcEntry *)(a1), (Pt1LcVec *)(a2))) /* merge_units */

int CompareSources(const void* a, const void* b);
void qsort(void* base, int n, int size, int (*cmp)(const void*, const void*));
void cShadowMan_AddParallelSource(char* s, V* dir, float k);
void cShadowMan_AddPointSource(char* s, V* pos, float k);
void cLightMan_AquireShadowSources(Mgr* m, V* pos);
}
static inline float Falloff(Light* l, float len)
{
    float a = MAX(0.0f, len - func_00372B00(l));
    float r = func_00372AF0(l) - func_00372B00(l);
    if (a < r) return 1.0f - a / r;
    return 0.0f;
}
static inline float Intensity(Light* l, V* pos, V* d)
{
    float k = 1.0f;
    switch (func_00372B30(l)) {
    case 2:
        if (d) cVector_opAssign(d, cParallelLight_GetDirection(l));
        break;
    case 4: {
        V t;
        cVector_opSub(&t, cLightSrc_GetPosition(l), pos);
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
        V t;
        cVector_opSub(&t, cLightSrc_GetPosition(l), pos);
        float len = cVector_GetLength(&t);
        V n;
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
extern "C" void cLightMan_AquireShadowSources(Mgr* m, V* pos)
{
    int left;
    int i;
    if (m->x14 || m->x18 || m->x1C) {
        m->candCount = 0;
        if (m->count) {
            FASTDMA_ToSPR(m->table, m->slots, m->count * 2);
            FASTDMA_Wait_ToSPR();
            int j;
            for (j = 0; j < m->count; j++) {
                if (m->table->entries[j].flags & 0x16)
                    cLightMan_AddLightScore(m, &m->table->entries[j], pos);
            }
            if (m->candCount)
                qsort(m->table->cand, m->candCount, 8, CompareSources);
        }
        left = D_00543794;
        for (i = 0; i < m->candCount && left; i++) {
            Light* l = m->table->cand[i].l;
            float s = l->scale;
            if (s <= 0.0f) continue;
            if (l->type == 2) {
                /* directional light: pass the reversed direction */
                V d = -l->dir;
                cShadowMan_AddParallelSource(D_00543790, &d, s);
            } else {
                float k = Intensity(l, pos, 0);
                cShadowMan_AddPointSource(D_00543790, &l->pos, k * s);
            }
            left--;
        }
    }
}
#undef func_00372AE0 /* merge_units */
#undef cSceneLight_GetDirection /* merge_units */
#undef cSceneLight_GetFalloffAngleCos /* merge_units */
#undef cVector_opSub /* merge_units */
#undef cVector_GetLength /* merge_units */
#undef cVector_Dot /* merge_units */
#undef FASTDMA_ToSPR /* merge_units */
#undef cLightMan_AddLightScore /* merge_units */
static inline void merge_flush_func_00372C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372C50 */

/* merge_units: begin func_003730F0 */
#pragma push /* merge_units */
/* light candidate test: range/cone check, appends (light, key) to the gather list */
typedef struct Pt1LcVec { float x, y, z, w; } __attribute__((aligned(16))) Pt1LcVec;
typedef struct Pt1LcEntry {
    unsigned char flags;
    char pad1[3];
    void* light;
    float range;
    float weight;
    Pt1LcVec pos;
} Pt1LcEntry;
typedef struct Pt1LcCand { void* light; float key; } Pt1LcCand;
typedef struct Pt1LcList { char pad[0x2000]; Pt1LcCand cand[1]; } Pt1LcList;
typedef struct Pt1LcGather {
    char pad0[0x50];
    int count;
    Pt1LcList* list;
} Pt1LcGather;
#if 0 /* merge_units */
extern void cVector_opSub(Pt1LcVec* out, Pt1LcVec* a, Pt1LcVec* b);
#endif /* merge_units */
#define cVector_opSub(a0, a1, a2) (cVector_opSub((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

extern void cVector_ctor_cVectorR(Pt1LcVec* out, Pt1LcVec* src);
extern void cVector_GetNormalized_void(Pt1LcVec* out, Pt1LcVec* src);
#if 0 /* merge_units */
extern float cVector_Dot(Pt1LcVec* a, Pt1LcVec* b);
#endif /* merge_units */
#define cVector_Dot(a0, a1) (cVector_Dot((void *)(a0), (void *)(a1))) /* merge_units */

extern float cSceneLight_GetFalloffAngleCos(void* light);
#if 0 /* merge_units */
extern Pt1LcVec* cSceneLight_GetDirection(void* light);
#endif /* merge_units */
#define cSceneLight_GetDirection(a0) ((Pt1LcVec *)cSceneLight_GetDirection((a0))) /* merge_units */

extern float func_00372AE0(void* light);
#if 0 /* merge_units */
extern float cVector_GetLengthSquared(Pt1LcVec* v);
#endif /* merge_units */
float cVector_GetLengthSquared(); /* merge_units */



void cLightMan_AddLightScore(Pt1LcGather* g, Pt1LcEntry* e, Pt1LcVec* pos)
{
    Pt1LcVec dir;
    Pt1LcVec n;
    Pt1LcVec d;
    Pt1LcVec v;
    float key;
    float outer;
    unsigned char ok = 0;
    void* light;

    if (e->flags & 0x14) {
        cVector_opSub(&d, pos, &e->pos);
        key = cVector_GetLengthSquared(&d);
        if (key < e->range * e->range) {
            ok = 1;
            key *= e->weight;
            if (e->flags == 0x10) {
                light = e->light;
                if (func_00372AE0(light) != 1.0f) {
                    cVector_ctor_cVectorR(&dir, cSceneLight_GetDirection(light));
                    cVector_opSub(&v, &e->pos, pos);
                    cVector_GetNormalized_void(&n, &v);
                    outer = 1.0f - cSceneLight_GetFalloffAngleCos(light);
                    if (!(1.0f - cVector_Dot(&dir, &n) <= outer))
                        ok = 0;
                }
            }
        }
    } else if (e->flags == 2) {
        key = 0.0f;
        ok = 1;
    }
    if (ok) {
        g->list->cand[g->count].key = key;
        g->list->cand[g->count].light = e->light;
        g->count++;
    }
}
#undef cVector_opSub /* merge_units */
#undef cVector_Dot /* merge_units */
#undef cSceneLight_GetDirection /* merge_units */
static inline void merge_flush_func_003730F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003730F0 */

/* merge_units: begin func_00373290 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
float cVector_GetLengthSquared(V4* a) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
static inline void merge_flush_func_00373290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373290 */

/* merge_units: begin func_003732C0 */
#pragma push /* merge_units */
/* Busy-waits until bit 8 of the hardware register 0x1000D400 clears. */
void FASTDMA_Wait_ToSPR(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
static inline void merge_flush_func_003732C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003732C0 */

/* merge_units: begin func_003732F0 */
#pragma push /* merge_units */
void FASTDMA_ToSPR(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void merge_flush_func_003732F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003732F0 */

/* merge_units: begin func_00373320 */
#pragma push /* merge_units */
/* cLightMan_Update: rebuild the sorted light candidate list when dirty, then emit */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Pt1GlV4;
typedef struct Pt1GlEntry { unsigned char flags; char pad1[0x1F]; } Pt1GlEntry;
typedef struct Pt1GlCand { void* light; float key; } Pt1GlCand;
typedef struct Pt1GlTable { Pt1GlEntry entries[0x100]; Pt1GlCand cand[1]; } Pt1GlTable;
typedef struct Pt1GlMgr {
    char pad0[0x20];
    char xform[0x10];
    Pt1GlV4 center;
    unsigned char pointMode;
    unsigned char force;
    unsigned char dirty;
    char pad43;
    unsigned int lastMask;
    char pad48[4];
    int count;
    int candCount;
    Pt1GlTable* table;
    char pad58[8];
    char slots[0x10];
} Pt1GlMgr;
#if 0 /* merge_units */
extern void FASTDMA_ToSPR(Pt1GlTable* table, void* slots, int n);
#endif /* merge_units */
#define FASTDMA_ToSPR(a0, a1, a2) (FASTDMA_ToSPR((int)(a0), (int)(a1), (a2))) /* merge_units */


extern void FASTDMA_Wait_ToSPR(void);
#if 0 /* merge_units */
extern void cLightMan_AddLightScore(Pt1GlMgr* m, Pt1GlEntry* e, void* xform);
#endif /* merge_units */
#define cLightMan_AddLightScore(a0, a1, a2) (cLightMan_AddLightScore((Pt1LcGather *)(a0), (Pt1LcEntry *)(a1), (Pt1LcVec *)(a2))) /* merge_units */


extern void cLightMan_AddLightScoreBox(Pt1GlMgr* m, Pt1GlV4* pos, Pt1GlEntry* e, float radius);
extern void cBox_Center(Pt1GlV4* out, void* xform);
#if 0 /* merge_units */
extern void cVector_opSub(Pt1GlV4* out, Pt1GlV4* a, Pt1GlV4* b);
#endif /* merge_units */
#define cVector_opSub(a0, a1, a2) (cVector_opSub((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */


#if 0 /* merge_units */
extern float cVector_GetLength(Pt1GlV4* v);
#endif /* merge_units */
#define cVector_GetLength(a0) (cVector_GetLength((void *)(a0))) /* merge_units */

extern int CompareSources(const void* a, const void* b);
extern void qsort(void* base, int n, int size, int (*cmp)(const void*, const void*));
extern void cLightMan_UpdateSources(Pt1GlMgr* m, unsigned int mask, unsigned int flags);
extern void cLightMan_VU1PreparePoint(Pt1GlMgr* m, void* out);
extern void cLightMan_VU1PrepareParallel(Pt1GlMgr* m, void* out);

void cLightMan_Update(Pt1GlMgr* m, unsigned int mask, unsigned int flags, void* out)
{
    if (m->force) {
        m->dirty = 1;
        m->force = 0;
    }
    if (!m->dirty && mask != m->lastMask)
        m->dirty = 1;
    if (m->dirty) {
        if (m->pointMode) {
            m->candCount = 0;
            if (m->count) {
                int i;
                FASTDMA_ToSPR(m->table, m->slots, m->count * 2);
                FASTDMA_Wait_ToSPR();
                for (i = 0; i < m->count; i++) {
                    if (mask & m->table->entries[i].flags)
                        cLightMan_AddLightScore(m, &m->table->entries[i], m->xform);
                }
                if (m->candCount)
                    qsort(m->table->cand, m->candCount, 8, CompareSources);
            }
        } else {
            m->candCount = 0;
            if (m->count) {
                Pt1GlV4 pos;
                Pt1GlV4 d;
                float radius;
                int i;
                FASTDMA_ToSPR(m->table, m->slots, m->count * 2);
                FASTDMA_Wait_ToSPR();
                cBox_Center(&pos, m->xform);
                cVector_opSub(&d, &m->center, &pos);
                radius = cVector_GetLength(&d);
                for (i = 0; i < m->count; i++) {
                    if (mask & m->table->entries[i].flags)
                        cLightMan_AddLightScoreBox(m, &pos, &m->table->entries[i], radius);
                }
                if (m->candCount)
                    qsort(m->table->cand, m->candCount, 8, CompareSources);
            }
        }
        m->dirty = 0;
        m->lastMask = mask;
        cLightMan_UpdateSources(m, mask, flags);
    }
    if (flags & 4)
        cLightMan_VU1PreparePoint(m, out);
    if (flags & 2)
        cLightMan_VU1PrepareParallel(m, out);
}
#undef FASTDMA_ToSPR /* merge_units */
#undef cLightMan_AddLightScore /* merge_units */
#undef cVector_opSub /* merge_units */
#undef cVector_GetLength /* merge_units */
static inline void merge_flush_func_00373320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373320 */
