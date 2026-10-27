#include "types.h"
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
extern void FASTDMA_ToSPR(Pt1GlTable* table, void* slots, int n);
extern void FASTDMA_Wait_ToSPR(void);
extern void cLightMan_AddLightScore(Pt1GlMgr* m, Pt1GlEntry* e, void* xform);
extern void cLightMan_AddLightScoreBox(Pt1GlMgr* m, Pt1GlV4* pos, Pt1GlEntry* e, float radius);
extern void cBox_Center(Pt1GlV4* out, void* xform);
extern void cVector_opSub(Pt1GlV4* out, Pt1GlV4* a, Pt1GlV4* b);
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