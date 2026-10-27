/*
 * Libs/SFOLib/Source/lights: 1 file, 00372120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00372120 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(float a, float b, float c) { x = a; y = b; z = c; w = 0.0f; }
    V(const V& o) { void* xx = this; Q1(this, &o); }
    V& operator=(const V& o) { void* xx = this; Q1(this, &o); return *this; }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    V& operator*=(float s) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(this), "f"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct C {
    float r, g, b, a;
    C() {}
    C(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; }
};
struct Light {
    char pad[0x1D]; unsigned char b1D; unsigned char b1E; char pad1F;
    float f20, f24, f28; char pad2C[4];
    V v30; V v40;
};
struct Amb { char pad[0x1C]; unsigned char b1C; char pad1D[3]; float f20, f24, f28; char pad2C[0x40 - 0x2C]; };
struct Ent { Light* l; int x; };
struct Out { char pad[0x2000]; Ent ents[0x100]; V dirs[4]; C cols[4]; };
struct Ctx {
    Amb* amb; char pad4[0xC]; int nAmb; char pad14[0xC];
    V pos; char pad30[0x43 - 0x30]; unsigned char b43; char pad44[4];
    int n48; int n4C; int n50; Out* out;
    char pad58[0x2060 - 0x58]; V v2060;
    char pad2070[0x2130 - 0x2070]; int n2130; Light* lights[6];
    char pad214C[0x2220 - 0x214C]; unsigned char b2220; unsigned char b2221; char pad2222[0xE];
    V v2230; V v2240;
};
extern "C" {
unsigned char func_00372B30(Light* l);
V* cParallelLight_GetDirection(Light* l);
V* cLightSrc_GetPosition(Light* l);
float func_00372B00(Light* l);
float func_00372AF0(Light* l);
float func_00372AE0(Light* l);
V* cSceneLight_GetDirection(Light* l);
float cSceneLight_GetFalloffAngleCos(Light* l);
void cVector_opAssign(V* d, const V* s);
void cVector_opSub(V* o, const V* a, const V* b);
float cVector_GetLength(const V* v);
float cVector_Dot(const V* a, const V* b);
V* cVector_ctor_void(V* v);
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
static inline float Intensity(Light* l, Ctx* c, V* d)
{
    float k = 1.0f;
    switch (func_00372B30(l)) {
    case 2:
        if (d) cVector_opAssign(d, cParallelLight_GetDirection(l));
        break;
    case 4: {
        V t;
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
        V t;
        cVector_opSub(&t, cLightSrc_GetPosition(l), &c->pos);
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
            V* d = &c->out->dirs[c->n48];
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
            c->out->dirs[c->n48] = V(0.0f, 0.0f, 0.0f, 0.0f);
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
                if (a->b1C) c->v2060 += V(a->f20, a->f24, a->f28);
            }
        }
        float s = 128.0f;
        V* a = &c->v2060;
        *a *= s;
        c->v2060.w = s;
    }
}
static inline void merge_flush_func_00372120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372120 */
