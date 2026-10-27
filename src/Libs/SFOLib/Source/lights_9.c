/*
 * Libs/SFOLib/Source/lights: 2 files, 00374740-003747A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00374740 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "self_call_dtor.h"

DEFINE_SELF_CALL_DTOR(cLightMan_dtor, cLightMan_DeallocateLightSources)
static inline void merge_flush_func_00374740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00374740 */

/* merge_units: begin func_003747A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* cLightMan_ctor: the LightMgr constructor (g_LightMgr, StaticInit_lights.c): bounds set to the
 * inverted extreme box, the scratchpad light table at 0x70000000, everything else cleared,
 * then the per-frame Reset. Returns the object as a constructor does (retail's move v0,a0). */
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V(const V& o) { void* xx = this; Q1(this, &o); }
    V& operator=(const V& o) { void* xx = this; Q1(this, &o); return *this; }
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct IV {
    int x, y, z, w;
    IV() {}
    IV(int a, int b, int c, int d) : x(a), y(b), z(c), w(d) {}
    IV& operator=(const IV& o) { void* xx = this; Q1(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W4 { int a, b, c, d; W4() {} W4(int i) : a(i), b(i), c(i), d(i) {} };
struct Entry { char pad0[2]; unsigned char flags; char pad3[0x1D]; };
struct Slot { char pad[0x20]; };
struct Table;
struct LightMgr {
    int x00, x04, x08, x0C;
    int x10, x14, x18, x1C;
    V bmin, bmax;
    unsigned char b40, b41, b42, b43;
    int x44, x48, x4C, x50;
    Table* table;
    char pad58[8];
    Entry entries[256];
    IV x2060;
    V mats[12];
    int x2130;
    int x2134[6];
    char pad214C[4];
    Slot slots[6];
    W4 x2210;
    unsigned char b2220, b2221;
    char pad2222[0xE];
    V x2230;
    V x2240;
    void Reset();
};
extern "C" LightMgr* cLightMan_ctor(LightMgr* m);

inline void LightMgr::Reset()
{
    x4C = 0;
    x50 = 0;
    x48 = 0;
    x2130 = 0;
    x2210 = W4(0);
    bmin = V(0.0f, 0.0f, 0.0f, 0.0f);
    bmax = V(0.0f, 0.0f, 0.0f, 0.0f);
    b40 = 1;
    b41 = 1;
    b42 = 1;
    x44 = 0;
    b2220 = 0;
    b2221 = 0;
    x2230 = V(0.0f, 0.0f, 0.0f, 0.0f);
    x2240 = V(0.0f, 0.0f, 0.0f, 0.0f);
}

extern "C" LightMgr* cLightMan_ctor(LightMgr* m)
{
    int i;
    int j;
    m->bmin.x = 3.4028235e38f; m->bmin.y = 3.4028235e38f; m->bmin.z = 3.4028235e38f; m->bmin.w = 1.0f;
    m->bmax.x = -3.4028235e38f; m->bmax.y = -3.4028235e38f; m->bmax.z = -3.4028235e38f; m->bmax.w = 1.0f;
    /* stand-ins for the construction of the entries[] and slots[] members (empty constructors) */
    { Entry* q = m->entries; do { q++; } while (q != m->entries + 256); }
    { Slot* q = m->slots; do { q++; } while (q != m->slots + 6); }
    m->table = (Table*)0x70000000;
    m->x10 = 0; m->x14 = 0; m->x18 = 0; m->x1C = 0;
    m->x00 = 0; m->x04 = 0; m->x08 = 0; m->x0C = 0;
    m->x2060 = IV(0, 0, 0, 0);
    m->mats[0].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[1].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[2].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[3].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[4].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[5].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[6].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[7].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[8].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[9].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[10].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->mats[11].Set(0.0f, 0.0f, 0.0f, 0.0f);
    m->b43 = 1;
    for (i = 0; i < 6; i++) m->x2134[i] = 0;
    for (j = 0; j < 256; j++) m->entries[j].flags = 0;
    m->Reset();
    return m;

}
static inline void merge_flush_func_003747A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003747A0 */
