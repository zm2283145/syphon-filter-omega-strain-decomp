/*
 * SFOGame/Source/taser: 5 files, 00264360-00264980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00264360 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "taser_types.h"

/* &v->data[i] */
TaserEntry* std_vector_TaserPoint_opIndex(TaserVec* v, int i) {
    return &v->data[i];
}
static inline void merge_flush_func_00264360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264360 */

/* merge_units: begin func_00264370 */
#pragma push /* merge_units */
typedef struct E264370 {
    char p0[0x10]; float f10; char p14[4]; float f18; char p1c[4];
    float f20; char p24[4]; float f28; char p2c[4]; float f30; float f34; char p38[8];
} E264370;
typedef struct { char p[0x14]; int n; E264370* d; } V264370;
extern float D_0048B110;
extern float D_0048B128;
extern float D_0048B138;
extern float D_0048B178;
extern float D_0048B1B8;
static inline float Abs264370(float x) { float r; asm { abs.s r, x } return r; }
static inline float Sign264370(float x) { return x > 0.0f ? 1.0f : -1.0f; }
static inline E264370* Get264370(V264370* v, int i) { return &v->d[i]; }
static inline float Calc264370(float k, float* p, float x, int flag)
{
    float d = k * -x;
    float sp = Sign264370(*p);
    float sd = Sign264370(d);
    if (sd != sp) d *= 2.0f;
    if (flag && Abs264370(d) < D_0048B128) d *= D_0048B138;
    return d;
}
#pragma opt_strength_reduction off
void cAirTaser_AddTension(V264370* v, float dt, int flag)
{
    int i;
    float k = D_0048B110 * dt;
    int n = v->n;
    for (i = 1; i < n - 1; i++) {
        E264370* e = Get264370(v, i);
        float* p = &e->f20;
        float d = Calc264370(k, p, e->f10, flag);
        {
            float a = Abs264370(d * D_0048B178);
            float lo = D_0048B1B8;
            float hi = 1.0f;
            asm {
                max.s a, a, lo
                min.s a, a, hi
            }
            Get264370(v, i)->f30 = Get264370(v, i)->f34 = a;
        }
        *p += d;
        e = Get264370(v, i);
        p = &e->f28;
        d = Calc264370(k, p, e->f18, flag);
        *p += d;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00264370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00264370 */

/* merge_units: begin func_00264530 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* lq/sq quad copies and VU0 vector ops as GCC-style volatile asm; the unused xx keeps retail's dead addiu.
   axis/up are declared before the scoped d so the stack slots match (up at 0x80, d at 0x70). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void VSub(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
struct M {
    V r[3]; V t;
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
};
struct Pt { V pos; V src; char pad[0x20]; };
struct Path {
    char pad[0x14];
    int n;
    Pt* p;
    char pad1C[0x60 - 0x1C];
    M m;
    Pt*& P() { return p; }
};
extern "C" {
#if 0 /* merge_units */
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
#endif /* merge_units */
void* cVector_ctor_float_float_float_float(void*, float, float, float, float); /* merge_units */
#define cVector_ctor_float_float_float_float(a0, a1, a2, a3, a4) ((V *)cVector_ctor_float_float_float_float((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
void cVector_GetNormalized_void(V* out, V* v);
#endif /* merge_units */
void cVector_GetNormalized_void(void*, void*); /* merge_units */
#define cVector_GetNormalized_void(a0, a1) (cVector_GetNormalized_void((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cVector_Cross(V* out, V* a, V* b);
#endif /* merge_units */
void cVector_Cross(void*, void*, void*); /* merge_units */
#define cVector_Cross(a0, a1, a2) (cVector_Cross((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
V* cVector_Normalize_void(V* v);
#endif /* merge_units */
void* cVector_Normalize_void(void*); /* merge_units */
#define cVector_Normalize_void(a0) ((V *)cVector_Normalize_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V* cVector_ctor_cVectorR(V* d, V* s);
#endif /* merge_units */
void* cVector_ctor_cVectorR(void*, void*); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
int cVector_IsZeroXYZ(V* v);
#endif /* merge_units */
int cVector_IsZeroXYZ(void*); /* merge_units */
#define cVector_IsZeroXYZ(a0) (cVector_IsZeroXYZ((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
#endif /* merge_units */
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(void*, void*, void*, void*, void*); /* merge_units */
#define cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(a0, a1, a2, a3, a4) (cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR((void *)(a0), (void *)(a1), (void *)(a2), (void *)(a3), (void *)(a4))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* axis);
#endif /* merge_units */
void cMatrix_MakeLookAtMatrix_cVectorR(void*, void*); /* merge_units */
#define cMatrix_MakeLookAtMatrix_cVectorR(a0, a1) (cMatrix_MakeLookAtMatrix_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetUnit(M* m);
#endif /* merge_units */
void cMatrix_SetUnit(void*); /* merge_units */
#define cMatrix_SetUnit(a0) (cMatrix_SetUnit((void *)(a0))) /* merge_units */

}
extern "C" void cAirTaser_PointsToWorld(Path* s, V* org)
{
    s->p[0].pos = *org;
    V axis;
    V up;
    {
        V d;
        VSub(&d, &(&s->P()[s->n])[-1].pos, &s->P()[0].pos);
        axis = d;
    }
    up.Set(0.0f, 0.0f, 1.0f, 1.0f);
    {
        V c;
    cVector_Cross(&c, &axis, &up);
    if (!cVector_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, &axis);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&s->m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&axis)) {
        cMatrix_MakeLookAtMatrix_cVectorR(&s->m, &axis);
    } else {
        cMatrix_SetUnit(&s->m);
    }
    }
    V* t = &s->m.t; *t = s->P()[0].pos;
    int n = s->n;
    for (int i = 0; i < n; i++) {
        s->P()[i].pos = s->P()[i].src;
        s->m.Apply(&s->P()[i].pos);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00264530(void) {}
#undef cVector_ctor_float_float_float_float /* merge_units */
#undef cVector_GetNormalized_void /* merge_units */
#undef cVector_Cross /* merge_units */
#undef cVector_Normalize_void /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_IsZeroXYZ /* merge_units */
#undef cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR /* merge_units */
#undef cMatrix_MakeLookAtMatrix_cVectorR /* merge_units */
#undef cMatrix_SetUnit /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264530 */

/* merge_units: begin func_00264720 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_00264720 {
    float x, y, z, w;
    V_00264720() {}
    V_00264720(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V_00264720(const V_00264720& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V_00264720& operator=(const V_00264720& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
    V_00264720 operator-(const V_00264720& b) const {
        V_00264720 c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
} __attribute__((aligned(16)));
struct M_00264720 {
    V_00264720 r0, r1, r2, t;
    M_00264720() {}
    M_00264720& operator=(const M_00264720& o) { M_00264720* d = this; const M_00264720* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M_00264720(const M_00264720& o) { const M_00264720* s = &o; M_00264720* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V_00264720* v, M_00264720* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct Pt_00264720 { V_00264720 pos; V_00264720 loc; char pad[0x20]; };
struct Arr { Pt_00264720* data; Pt_00264720& operator[](int i) { Arr* t = this; return t->data[i]; }
    Pt_00264720& Back(int n) { Arr* t = this; Pt_00264720* e = t->data + n; return e[-1]; } };
struct Obj { char pad[0x14]; int n; Arr arr; char pad1c[0x44]; M_00264720 m; };
extern "C" {
#if 0 /* merge_units */
V_00264720* cVector_ctor_float_float_float_float(V_00264720* v, float x, float y, float z, float w);
#endif /* merge_units */
#define cVector_ctor_float_float_float_float(a0, a1, a2, a3, a4) ((V_00264720 *)cVector_ctor_float_float_float_float((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
void cVector_GetNormalized_void(V_00264720* out, V_00264720* v);
#endif /* merge_units */
#define cVector_GetNormalized_void(a0, a1) (cVector_GetNormalized_void((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cVector_Cross(V_00264720* out, V_00264720* a, V_00264720* b);
#endif /* merge_units */
#define cVector_Cross(a0, a1, a2) (cVector_Cross((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
int cVector_IsZeroXYZ(V_00264720* v);
#endif /* merge_units */
#define cVector_IsZeroXYZ(a0) (cVector_IsZeroXYZ((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_00264720* cVector_Normalize_void(V_00264720* v);
#endif /* merge_units */
#define cVector_Normalize_void(a0) ((V_00264720 *)cVector_Normalize_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_00264720* cVector_ctor_cVectorR(V_00264720* d, V_00264720* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V_00264720 *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M_00264720* m, V_00264720* a, V_00264720* b, V_00264720* c, V_00264720* t);
#endif /* merge_units */
#define cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(a0, a1, a2, a3, a4) (cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR((void *)(a0), (void *)(a1), (void *)(a2), (void *)(a3), (void *)(a4))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_MakeLookAtMatrix_cVectorR(M_00264720* m, V_00264720* a);
#endif /* merge_units */
#define cMatrix_MakeLookAtMatrix_cVectorR(a0, a1) (cMatrix_MakeLookAtMatrix_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetUnit(M_00264720* m);
#endif /* merge_units */
#define cMatrix_SetUnit(a0) (cMatrix_SetUnit((void *)(a0))) /* merge_units */

void cMatrix_InvertRot(M_00264720* m);
int cMatrix_IsZeroTranslation(M_00264720* m);
V_00264720* func_00133EC0(M_00264720* m);
void cVector_NegateXYZ(V_00264720* v);
void cVector_Rotate_cMatrixR(V_00264720* v, M_00264720* m);
void cMatrix_SetTranslation(M_00264720* m, V_00264720* v);
void cAirTaser_PointsToLocal(Obj* s, V_00264720* p);
}
static inline void LookFrame(M_00264720* m, V_00264720* dir, V_00264720* up)
{
    V_00264720 c;
    cVector_Cross(&c, dir, up);
    if (!cVector_IsZeroXYZ(&c)) {
        V_00264720 f;
        V_00264720 r;
        V_00264720 u;
        V_00264720 w;
        cVector_GetNormalized_void(&f, dir);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, dir);
    } else {
        cMatrix_SetUnit(m);
    }
}
static inline void InvertRigid(M_00264720* m)
{
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        V_00264720 t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
void cAirTaser_PointsToLocal(Obj* s, V_00264720* p)
{
    s->arr[0].pos = *p;
    V_00264720 dir = s->arr.Back(s->n).pos - s->arr[0].pos;
    M_00264720 inv;
    V_00264720 up(0.0f, 0.0f, 1.0f, 1.0f);
    LookFrame(&s->m, &dir, &up);
    V_00264720& mt = s->m.t; mt = s->arr[0].pos;
    inv = s->m;
    InvertRigid(&inv);
    int n = s->n;
    for (int i = 0; i < n; i++) {
        s->arr[i].loc = s->arr[i].pos;
        MulV(&s->arr[i].loc, &inv);
    }
}
#undef cVector_ctor_float_float_float_float /* merge_units */
#undef cVector_GetNormalized_void /* merge_units */
#undef cVector_Cross /* merge_units */
#undef cVector_IsZeroXYZ /* merge_units */
#undef cVector_Normalize_void /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR /* merge_units */
#undef cMatrix_MakeLookAtMatrix_cVectorR /* merge_units */
#undef cMatrix_SetUnit /* merge_units */
static inline void merge_flush_func_00264720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264720 */

/* merge_units: begin func_00264980 */
#pragma push /* merge_units */
// 00264980 cAirTaser_BeginShocking_cHumanP_int_cVector -- cAirTaser::BeginShocking(cHuman*, int, cVector) (taser.cc). l7 match.
// AI noise message and cVector are expression temporaries (prototype has no locals for them); temp dtor weak in .dtors_drop.
#pragma cplusplus on

typedef struct HStr { char d[0x9C]; } HStr;
typedef struct HSnd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    HStr s78;
    HStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) HSnd;
typedef struct HNoiseMsg { void* vt; char pad4[0x4C]; } HNoiseMsg;
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" char D_004D92A0[];
#pragma define_section ALLOC_GUARD_DTOR ".dtors_drop" far_absolute RX
struct AiMsg : HNoiseMsg { __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AiMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); } };
struct V_00264980 {
    float x, y, z, w;
    V_00264980() {}
    V_00264980& operator=(const V_00264980& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
    V_00264980(const V_00264980& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct HTarget { void* vt; char pad4[8]; int serial; };
typedef struct HActor { char pad0[0xC]; int pos[2]; int* Id() { return pos; } const int& IdR() const { return pos[0]; } } HActor;
typedef struct HDef { char pad0[0xFC]; float fFC; float Get() const { return fFC; } } HDef;
typedef struct HeldItem {
    HDef* def;
    HActor* actor;
    unsigned char state;
    char pad9[0x2C - 9];
    HTarget* hp;
    int hserial;
    char pad34[8];
    void* x3C;
    V_00264980 pos;
    char pad50[0xB4 - 0x50];
    int xB4;
    float xB8;
    unsigned char bBC;
    unsigned char bBD;
    static bool Same(int a, int b) { return a == b; }
    bool Valid() { return !hp || Same(hp->serial, hserial); }
    HTarget* Get() { return Valid() ? hp : 0; }
    void Set(HTarget* o) { hp = o; int d; hserial = *(o ? &o->serial : (d = -1, &d)); }
} HeldItem;

extern "C" {
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void cHuman_SetParticleEffect(HTarget* a, int kind, int b, float f);
extern void cPlaySoundMsg_ctor_cSndFxR(HSnd* e, void* preset, void* owner);
extern void cFileMan_dtor(HStr* s, int flag);
extern void* cSystemContainer_GetSystem(void* w, void* key);
extern void* cHuman_GetFloorAnchor_void_2(HTarget* a);
extern V_00264980* cSkaAnimAnchor_GetPosition(void* r);
#if 0 /* merge_units */
extern V_00264980* cVector_ctor_cVectorR(V_00264980* d, V_00264980* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V_00264980 *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

extern AiMsg cAISoundSystemGOBJPositionMessage_ctor(const int& id, const V_00264980& pos, int kind, float a, float b);
extern char D_004F12D0[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004EE5C0[];
#if 0 /* merge_units */
extern char D_004D92A0[];
#endif /* merge_units */
#define D_004D92A0 ((char*)&D_004D92A0) /* merge_units */

void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* s, HTarget* t, void* a2, V_00264980* pos);
}

inline void Queue(const HNoiseMsg& m, void* sys, int imm) { QueueMessage_cMessageR_cSystemP_int((void*)&m, sys, imm); }
struct VC : V_00264980 { VC(const V_00264980& o) { cVector_ctor_cVectorR(this, (V_00264980*)&o); } };
void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* s, HTarget* t, void* a2, V_00264980* pos)
{
    s->state = 2;
    s->xB4 = 0;
    s->bBD = 0;
    s->bBC = 0;
    s->Set(t);
    s->xB8 = 10000.0f;
    s->x3C = a2;
    s->pos = *pos;
    cHuman_SetParticleEffect(s->Get(), 2, 1, 1.0f);
    {
        HSnd ev;
        cPlaySoundMsg_ctor_cSndFxR(&ev, D_004F12D0, s->Get());
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
        {
            void* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
            /* the message is a temporary built by its (out-of-line) ctor: returned by value via the hidden a0 pointer */
            Queue(cAISoundSystemGOBJPositionMessage_ctor(*s->actor->Id(), VC(*cSkaAnimAnchor_GetPosition(cHuman_GetFloorAnchor_void_2(t))), 4, 1.0f, s->def->fFC), svc, 0);
        }
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}
#undef cVector_ctor_cVectorR /* merge_units */
#undef D_004D92A0 /* merge_units */
static inline void merge_flush_func_00264980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264980 */
