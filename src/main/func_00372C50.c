#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* LightMgr_CollectNear: rebuild the point/spot light candidates around pos (TestPointSpot,
 * sorted by LightMgr_CompareOrder) and hand the strongest ones to the shadow system:
 * directional lights as a reversed direction, the others as a position weighted by
 * their intensity at pos. Intensity is LightMgr_BuildLightSlots' (LightMgr_BuildLightSlots.c). */
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
V* func_00372B20(Light* l);
V* func_00372B10(Light* l);
float func_00372B00(Light* l);
float func_00372AF0(Light* l);
float func_00372AE0(Light* l);
V* func_00372AD0(Light* l);
float func_00372AC0(Light* l);
void Vec4_Copy(V* d, const V* s);
void Sphere_FromCenter(V* o, const V* a, const V* b);
float Vec4_Length(const V* v);
float Vec4_Dot3(const V* a, const V* b);
V* Ptr_Identity(V* v);
float Math_MaxF(float a, float b);
float Math_MinF(float a, float b);
void Dma_StartToSpr(Table* t, void* slots, int n);
void Dma_WaitToSpr(void);
void LightMgr_TestPointSpot(Mgr* m, Entry* e, V* pos);
int LightMgr_CompareOrder(const void* a, const void* b);
void qsort(void* base, int n, int size, int (*cmp)(const void*, const void*));
void Shadow_AddLightEntries(char* s, V* dir, float k);
void Shadow_AddEntry(char* s, V* pos, float k);
void LightMgr_CollectNear(Mgr* m, V* pos);
}
static inline float Falloff(Light* l, float len)
{
    float a = Math_MaxF(0.0f, len - func_00372B00(l));
    float r = func_00372AF0(l) - func_00372B00(l);
    if (a < r) return 1.0f - a / r;
    return 0.0f;
}
static inline float Intensity(Light* l, V* pos, V* d)
{
    float k = 1.0f;
    switch (func_00372B30(l)) {
    case 2:
        if (d) Vec4_Copy(d, func_00372B20(l));
        break;
    case 4: {
        V t;
        Sphere_FromCenter(&t, func_00372B10(l), pos);
        k = Vec4_Length(&t);
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
        Sphere_FromCenter(&t, func_00372B10(l), pos);
        float len = Vec4_Length(&t);
        V n;
        Ptr_Identity(&n);
        n.w = 0.0f;
        n.x = t.x / len;
        n.y = t.y / len;
        n.z = t.z / len;
        if (d) Vec4_Copy(d, &n);
        k = Falloff(l, len);
        if (func_00372AE0(l) != 1.0f) {
            float dot = Vec4_Dot3(func_00372AD0(l), &n);
            float lo = func_00372AC0(l);
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
    k = Math_MaxF(k, 0.0f);
    k = Math_MinF(k, 1.0f);
    return k;
}
extern "C" void LightMgr_CollectNear(Mgr* m, V* pos)
{
    int left;
    int i;
    if (m->x14 || m->x18 || m->x1C) {
        m->candCount = 0;
        if (m->count) {
            Dma_StartToSpr(m->table, m->slots, m->count * 2);
            Dma_WaitToSpr();
            int j;
            for (j = 0; j < m->count; j++) {
                if (m->table->entries[j].flags & 0x16)
                    LightMgr_TestPointSpot(m, &m->table->entries[j], pos);
            }
            if (m->candCount)
                qsort(m->table->cand, m->candCount, 8, LightMgr_CompareOrder);
        }
        left = D_00543794;
        for (i = 0; i < m->candCount && left; i++) {
            Light* l = m->table->cand[i].l;
            float s = l->scale;
            if (s <= 0.0f) continue;
            if (l->type == 2) {
                /* directional light: pass the reversed direction */
                V d = -l->dir;
                Shadow_AddLightEntries(D_00543790, &d, s);
            } else {
                float k = Intensity(l, pos, 0);
                Shadow_AddEntry(D_00543790, &l->pos, k * s);
            }
            left--;
        }
    }
}
