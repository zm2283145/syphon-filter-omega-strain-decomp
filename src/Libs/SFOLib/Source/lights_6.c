/*
 * Libs/SFOLib/Source/lights: 5 files, 003730F0-00373320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003730F0 */
#pragma push /* merge_units */
#include "types.h"
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
extern void cVector_opSub(Pt1LcVec* out, Pt1LcVec* a, Pt1LcVec* b);
extern void cVector_ctor_cVectorR(Pt1LcVec* out, Pt1LcVec* src);
extern void cVector_GetNormalized_void(Pt1LcVec* out, Pt1LcVec* src);
extern float cVector_Dot(Pt1LcVec* a, Pt1LcVec* b);
extern float cSceneLight_GetFalloffAngleCos(void* light);
extern Pt1LcVec* cSceneLight_GetDirection(void* light);
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
#define cVector_opSub(a0, a1, a2) (cVector_opSub((Pt1LcVec *)(a0), (Pt1LcVec *)(a1), (Pt1LcVec *)(a2))) /* merge_units */

extern float cVector_GetLength(Pt1GlV4* v);
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
static inline void merge_flush_func_00373320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373320 */
