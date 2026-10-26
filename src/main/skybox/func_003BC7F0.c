#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    V& r(int i) { return *(V*)m[i]; }
} __attribute__((aligned(16)));
struct TM { M m; };
struct VA : V { VA(float ax, float ay, float az, float aw) { void* xx = this; x = ax; y = ay; z = az; w = aw; } };

struct Sky {
    char p0[0x174];
    char model[0x1B0 - 0x174];
    V rot;
    V acc;
    char p1d0[8];
    float heading;
    char p1dc[4];
    V dir;
    V base;
    float ang;
    float angVel;
    float angMax;
    unsigned int flags;
};

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern int g_DrawMode;
extern float D_005392E0;
extern float D_005392E4;
extern float D_005392E8;
extern float D_005392EC;
float Math_Atan2f(float y, float x);
void cMatrix_ctor_void(TM* m);
void Mtx_MakeAxisRotation(TM* m, float x, float y, float z, float a);
void Mtx_Multiply(M* a, TM* b);
void Model_Draw(void* model, int mode, M* m);
void SkyLayer_Draw(Sky* o);
}

#define STK(i) ((M*)(g_Video + 0xA80 + (i) * 0x40))

static inline void UnitM(M* m) { M* p = m; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CpV(V* dst, const V* src) { V* p = dst; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(dst), "r"(src) : "memory"); }
static inline void Rot2(M* m, const V& ax, float a)
{
    TM t;
    cMatrix_ctor_void(&t);
    Mtx_MakeAxisRotation(&t, ax.x, ax.y, ax.z, a);
    Mtx_Multiply(m, &t);
}
static inline void Rot(M* m, const V& ax, float a) { Rot2(m, ax, a); }
static inline float AbsF(float a) { float r; __asm__ ("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }
static inline void SetFog(const V& c)
{
    float k = 128.0f;
    D_005392E0 = k * c.x;
    D_005392E4 = k * c.y;
    D_005392E8 = k * c.z;
    D_005392EC = k * c.w;
}

#define PI 3.1415927f
#define HPI 1.5707964f

void SkyLayer_Draw(Sky* o)
{
    int dm = g_DrawMode;
    if (o->flags & 0x10) {
        g_DrawMode = dm & ~0x4000;
        SetFog(V(0.0f, 0.0f, 0.0f, 0.0f));
    } else {
        g_DrawMode = dm | 0x4000;
        float r = AbsF(o->ang) / o->angMax;
        r = r < 1.0f ? r : 1.0f;
        SetFog(V(0.0f, 0.0f, 0.0f, -r));
    }
    if (o->flags & 8) {
        V row(STK(D_00538C64)->r(1));
        float a = Math_Atan2f(row.y, row.x);
        float prev = o->heading;
        if (prev != a) {
            float na = a;
            if (prev < -HPI && !(na <= HPI)) {
                na = na - (PI + prev);
                prev = prev * -1.0f;
            } else if (na < -HPI && !(prev <= HPI)) {
                prev = prev - (PI + na);
                na = na * -1.0f;
            }
            o->rot.z = o->rot.z + o->acc.z * (na - prev);
            o->heading = a;
        }
    }
    M mm;
    UnitM(&mm);
    Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), o->rot.x);
    Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), o->rot.y);
    Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), o->rot.z);
    CpV((V*)mm.m[3], &o->dir);
    Model_Draw(o->model, 2, &mm);
}
