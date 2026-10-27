/*
 * Libs/SFOLib/Source/skybox: 3 files, 003BC7F0-003BCB90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BC7F0 */
#pragma push /* merge_units */
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
float Libc_Atan2f(float y, float x);
void cMatrix_ctor_void(TM* m);
void cMatrix_SetWithAxisAngle(TM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, TM* b);
void cVU1Model_Render(void* model, int mode, M* m);
void cSLayer_Render(Sky* o);
}

#define STK(i) ((M*)(g_Video + 0xA80 + (i) * 0x40))

static inline void UnitM(M* m) { M* p = m; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CpV(V* dst, const V* src) { V* p = dst; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(dst), "r"(src) : "memory"); }
static inline void Rot2(M* m, const V& ax, float a)
{
    TM t;
    cMatrix_ctor_void(&t);
    cMatrix_SetWithAxisAngle(&t, ax.x, ax.y, ax.z, a);
    cMatrix_Rotate(m, &t);
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

void cSLayer_Render(Sky* o)
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
        float a = Libc_Atan2f(row.y, row.x);
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
    cVU1Model_Render(o->model, 2, &mm);
}
static inline void merge_flush_func_003BC7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC7F0 */

/* merge_units: begin func_003BCB90 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
char *strncpy(void *, const void *, int);

#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4 operator*(float s) const {
        V4 r; V4* q = &r; int t; const V4* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        return *q;
    }
    V4& operator=(const V4& a) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&a; *d = *s; return *this; }
    V4& operator+=(const V4& a) {
        V4* d = this; const V4* p = &a;
        asm {
            lqc2 vf1, 0x0(d)
            lqc2 vf2, 0x0(p)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct Sky_BCB90 {
    char p0[0x1B0];
    V4 vel;
    V4 acc;
    char p1d0[0x10];
    V4 dir;
    V4 base;
    float ang;
    float angVel;
    float angMax;
    unsigned int flags;
};
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
extern "C" void cSLayer_Update(Sky_BCB90* o) {
    o->ang = o->ang + o->angVel;
    if (!(o->flags & 8)) {
        o->vel += o->acc;
    }
    if (o->flags & 4) {
        { float a = o->ang; float m = o->angMax; if (a > m) o->ang = -m; }
        { float a; float m = o->angMax; a = o->ang; if (a < -m) o->ang = m; }
    }
    {
        V4* d; /* dead store: retail keeps the unused &dir addiu */
        o->dir = o->base * o->ang;
        d = &o->dir;
    }
    o->dir.w = 1.0f;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BCB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BCB90 */

/* merge_units: begin func_003BCC70 */
#pragma push /* merge_units */
typedef struct { int a[0x28]; } H3BC;
typedef struct { char pad[0x14C]; unsigned char b14c; } T3BC;
typedef struct { int a; char name[0x94]; T3BC* f98; } S3BC;
typedef struct { char pad[0x16C]; int f16c; unsigned char b170; char p171[3]; char f174[0x3C]; float m[24]; } O3BC;
extern void cHogFile_ctor(O3BC*);
extern void cVU1Model_ctor(char*);
extern void cFileMan_Open(S3BC*);
extern void cFileMan_Read_charPP_int(S3BC*, int*, int);
extern void cHogFile_Open(O3BC*, char*, int, int);
extern char* strchr(const char*, int);
extern void cFileMan_ctor_charP_cHogFileR_bool(H3BC*, char*, O3BC*, int);
extern void cVU1Model_Load(char*, H3BC*, int);
extern void cFileMan_dtor(H3BC*, int);
O3BC* cSLayer_ctor(O3BC* o, S3BC* src, int arg) {
    H3BC h;
    cHogFile_ctor(o);
    o->f16c = 0;
    cVU1Model_ctor(o->f174);
    o->m[0] = 0.0f; o->m[1] = 0.0f; o->m[2] = 0.0f; o->m[3] = 0.0f;
    o->m[4] = 0.0f; o->m[5] = 0.0f; o->m[6] = 0.0f; o->m[7] = 0.0f;
    o->m[8] = 0.0f; o->m[9] = 0.0f; o->m[10] = 0.0f; o->m[11] = 0.0f;
    o->m[12] = 0.0f; o->m[13] = 0.0f; o->m[14] = 0.0f; o->m[15] = 1.0f;
    o->m[16] = 0.0f; o->m[17] = 0.0f; o->m[18] = 0.0f; o->m[19] = 0.0f;
    o->m[20] = 0.0f; o->m[21] = 0.0f; o->m[22] = 0.0f; o->m[23] = 0.0f;
    cFileMan_Open(src);
    cFileMan_Read_charPP_int(src, &o->f16c, 0);
    if (src->f98->b14c == 2) o->b170 = 1;
    else o->b170 = 0;
    cHogFile_Open(o, src->name, o->f16c, 0);
    {
        char* name = src->name;
        strncpy(strchr(name, '.'), ".VUM", 4);
        cFileMan_ctor_charP_cHogFileR_bool(&h, name, o, 0);
    }
    cVU1Model_Load(o->f174, &h, arg);
    cFileMan_dtor(&h, -1);
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BCC70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BCC70 */
