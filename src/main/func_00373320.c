#include "types.h"
/* LightMgr_GatherModelLights: rebuild the sorted light candidate list when dirty, then emit */
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
extern void func_003732F0(Pt1GlTable* table, void* slots, int n);
extern void func_003732C0(void);
extern void func_003730F0(Pt1GlMgr* m, Pt1GlEntry* e, void* xform);
extern void func_00373590(Pt1GlMgr* m, Pt1GlV4* pos, Pt1GlEntry* e, float radius);
extern void func_001832D0(Pt1GlV4* out, void* xform);
extern void Sphere_FromCenter(Pt1GlV4* out, Pt1GlV4* a, Pt1GlV4* b);
extern float func_00183350(Pt1GlV4* v);
extern int func_00373BA0(const void* a, const void* b);
extern void func_001273C8(void* base, int n, int size, int (*cmp)(const void*, const void*));
extern void func_00372120(Pt1GlMgr* m, unsigned int mask, unsigned int flags);
extern void func_00371CF0(Pt1GlMgr* m, void* out);
extern void func_00371E70(Pt1GlMgr* m, void* out);

void func_00373320(Pt1GlMgr* m, unsigned int mask, unsigned int flags, void* out)
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
                func_003732F0(m->table, m->slots, m->count * 2);
                func_003732C0();
                for (i = 0; i < m->count; i++) {
                    if (mask & m->table->entries[i].flags)
                        func_003730F0(m, &m->table->entries[i], m->xform);
                }
                if (m->candCount)
                    func_001273C8(m->table->cand, m->candCount, 8, func_00373BA0);
            }
        } else {
            m->candCount = 0;
            if (m->count) {
                Pt1GlV4 pos;
                Pt1GlV4 d;
                float radius;
                int i;
                func_003732F0(m->table, m->slots, m->count * 2);
                func_003732C0();
                func_001832D0(&pos, m->xform);
                Sphere_FromCenter(&d, &m->center, &pos);
                radius = func_00183350(&d);
                for (i = 0; i < m->count; i++) {
                    if (mask & m->table->entries[i].flags)
                        func_00373590(m, &pos, &m->table->entries[i], radius);
                }
                if (m->candCount)
                    func_001273C8(m->table->cand, m->candCount, 8, func_00373BA0);
            }
        }
        m->dirty = 0;
        m->lastMask = mask;
        func_00372120(m, mask, flags);
    }
    if (flags & 4)
        func_00371CF0(m, out);
    if (flags & 2)
        func_00371E70(m, out);
}