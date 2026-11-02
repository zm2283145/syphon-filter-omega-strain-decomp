/*
 * SFOGame/Source/humanCollision: 5 files, 001EB800-001EB960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB800 */
#pragma push /* merge_units */
#include "types.h"
#include "humanCollision_types.h"

#if 0 /* merge_units */
extern void std_vector_imp_cEdgeGroup_ctor(HumanColVec* v);
#endif /* merge_units */
HumanColVec * std_vector_imp_cEdgeGroup_ctor(); /* merge_units */


extern void std_vector_imp_cEdgeGroup_reserve(HumanColVec* v, int capacity); /* vector reserve (buffer A) */

/* Constructor for buffer A: empty vector, reserve *capacity, store the flag byte; returns v. */
HumanColVec* cArray_cEdgeGroup_ctor(HumanColVec* v, int* capacity, char flag)
{
    std_vector_imp_cEdgeGroup_ctor(v);
    std_vector_imp_cEdgeGroup_reserve(v, *capacity);
    v->flag0C = flag;
    return v;
}
static inline void merge_flush_func_001EB800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB800 */

/* merge_units: begin func_001EB850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_imp_cCollisionEdge_reserve(int, int);  /* vector reserve (buffer B) */

/* Empty vector (buffer A). */
HumanColVec* std_vector_imp_cEdgeGroup_ctor(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int std_vector_cCollisionEdge_reserve(int v, int n) {
    return std_vector_imp_cCollisionEdge_reserve(v, n);
}

/* Empty vector (buffer B). */
HumanColVec* std_vector_cCollisionEdge_ctor(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}
static inline void merge_flush_func_001EB850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB850 */

/* merge_units: begin func_001EB8A0 */
#pragma push /* merge_units */
#define FLT_MAX 3.4028235e38f
extern void cBitArray_19_ctor_bool(HumanColMask* m, int all);
#if 0 /* merge_units */
extern void cBitArray_5_ctor_bool(HumanColMask* m, int all);
#endif /* merge_units */
HumanColMask* cBitArray_5_ctor_bool(HumanColMask* m, unsigned char all); /* merge_units */
#define cBitArray_5_ctor_bool(a0, a1) ((void)cBitArray_5_ctor_bool((a0), (unsigned char)(a1))) /* merge_units */

/* Constructor: clears the masks and sets unbounded ranges. */
HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_void(HumanColPreset* p)
{
    HumanColMask* masks;
    p->selector = -1;
    masks = p->masks;
    cBitArray_19_ctor_bool(&masks[0], 0);
    cBitArray_19_ctor_bool(&masks[1], 0);
    cBitArray_5_ctor_bool(&masks[2], 0);
    cBitArray_5_ctor_bool(&masks[3], 0);
    p->cfg.range0Min = -FLT_MAX;
    p->cfg.range0Max = FLT_MAX;
    p->cfg.range1Min = -FLT_MAX;
    p->cfg.range1Max = FLT_MAX;
    p->cfg.range2Min = -FLT_MAX;
    p->cfg.range2Max = FLT_MAX;
    p->cfg.enabled = 0;
    p->descFlag = 0;
    p->active = 0;
    p->unk32 = 0;
    p->unk70 = 0;
    p->unk90 = -1;
    p->unk94 = -1;
    p->unk98 = 0;
    p->unkA0 = 0;
    p->bestHeight = -FLT_MAX;
    p->unkE4 = 0;
    return p;
}
#undef cBitArray_5_ctor_bool /* merge_units */
static inline void merge_flush_func_001EB8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB8A0 */

/* merge_units: begin func_001EB960 */
#pragma push /* merge_units */
/* Mask constructor: all bits set when all == 1, else none. */
HumanColMask* cBitArray_5_ctor_bool(HumanColMask* m, unsigned char all) {
    if (all == 1) {
        m->bits = -1;
    } else {
        m->bits = 0;
    }
    return m;
}
static inline void merge_flush_func_001EB960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB960 */

/* merge_units: begin func_001EB990 */
#pragma push /* merge_units */
/* cHumanCollisionRoutine::cHumanCollisionRoutine() (humanCollision.cc).
 * Member sub-objects are initialised through small inline Init() members; their nesting depth places the
 * temporaries in retail's stack slots (MW allocates inline locals by depth). Fixed arrays use the empty
 * default-construct walk plus a goto fill loop (cf. bone_2.c). Inline asm is only EE/VU0 lq/sq/sqc2/vmul. */
#pragma opt_unroll_loops off
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, short) { const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(this) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct QV;
extern "C" QV* cQuatVec_ctor_cQuatVecR(QV* d, const QV* s);
struct QV {
    V rot, pos;
    QV() {}
    QV(const QV& o) { cQuatVec_ctor_cQuatVecR(this, &o); }
    static void CpT(V* d, const V* s) { V* pd = d; __int128 t; const V* ps = s; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    QV& operator=(const QV& o) { CpT(&rot, &o.rot); pos = o.pos; return *this; }
} __attribute__((aligned(16)));

extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern signed char D_004E1D80;
extern QV D_00497F00;
extern char D_004DA330[], D_004DAD00[], D_004DA3E0[], D_004DA810[], D_004DA800[], D_004DA820[];
extern float D_0048A968[], D_0048A970[];
extern float D_004A03E0;
extern V D_004A03F0;
extern unsigned char D_0048A990;
void cModeSwitch_12_ctor_uint(void* p, int v);
int func_001EC310(void* p, int v);
void cSplinedMotion_float_ctor_floatR_floatR(void* p, const float* a, const float* b);
void cQuaternion_GetIdentity(V* q);
void cVector_Get0001(V* v);
void cQuatVec_ctor_cQuaternionR_cVectorR(QV* p, const V* q, const V* v);
QV* cQuatVec_ctor_cQuatVecR(QV* d, const QV* s);
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
V* cVector_ctor_cVectorR(V* d, const V* s);
const V* cVector_GetZero(void);
void cPointMass_SetMass(void* p, float m);
void __construct_array(void* p, void* ctor, void* dtor, int size, int n);
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_ctor(void);
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor(void);
}

static inline const V& GetZero() {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline QV Ident0() {
    if (!D_004E1D80) {
        V q; V v;
        cQuaternion_GetIdentity(&q);
        cVector_Get0001(&v);
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
static inline QV Ident() { return Ident0(); }
static inline V Unit() { V r; V* p = &r; asm volatile { sqc2 vf0, 0x0(p) } return V(r, (short)0); }
/* noreorder block: retail schedules the plane copy's lq right after the destination address */
static inline V UnitQ() { V r; V* p = &r; asm volatile { .set noreorder; sqc2 vf0, 0x0(p); .set reorder } return *p; }
static inline void SetVF0(V* d, float x, float y, float z, float w) { cVector_ctor_cVectorR(d, cVector_ctor_float_float_float_float(&V(), x, y, z, w)); }
static inline void SetVF1(V* d, float x, float y, float z, float w) { SetVF0(d, x, y, z, w); }
static inline float DotX(const V* a, const V* b) { const V* A = a; const V* B = b; int t; float r = 0.0f; asm { lqc2 vf1, 0(A); lqc2 vf2, 0(B); vmul.xyzw vf3, vf1, vf2; mtsah zero, 6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddz.w vf4, vf0, vf3z; qmfc2.ni t, vf4; qfsrv t, t, t; mtc1 t, r } return r; }
static inline float Dot3W(const V* a, const V* b) { return DotX(a, b); }
struct Plane {
    float a, b, c, d;
    void Init(V p, const V& n) { float x, y, z, k; k = Dot3W(&n, &p); z = n.z; y = n.y; x = n.x; a = x; b = y; c = z; d = -k; }
};
struct Face {
    V vertices[3];
    V unitNormal;
    unsigned char flags; unsigned char ext; char name[14];
    char pad50[0x10];
    int loc0, loc1; int pad68[2];
    void Init() {
        Face* t = this;
        { V* p = t->vertices; do { ++p; } while (p != t->vertices + 3); }
        t->flags = 0; t->name[0] = 0; t->loc0 = 0; t->loc1 = 0;
    }
};
template <class T, int N> struct FA {
    T e[N];
    void Init(const T& v) {
        { T* p = e; do { ++p; } while (p != e + N); }
        int i = 0;
        goto test;
    loop:
        e[(unsigned)i] = v;
        i++;
    test:
        if (i <= N - 1) goto loop;
    }
};
struct B2 { unsigned char a, b; void Init() { a = 0; b = 0; } };

struct R {
    void* vtable;                 /* 0x000 */
    void* gobj; void* skel; void* anim;
    unsigned char b10, b11, b12, b13, b14;
    char p15[3];
    char modes[3][8];             /* 0x018 */
    int m30[3];                   /* 0x030 */
    char p3C[4];
    float q40[4]; float v50[4]; float f60; char p64[0xC];
    float q70[4]; float v80[4]; float f90; char p94[0xC];
    struct Spl { void* vt; char p[0x34]; void Init() { Spl* t = this; cSplinedMotion_float_ctor_floatR_floatR(t, D_0048A968, D_0048A970); t->vt = D_004DA3E0; } } spl; /* 0x0A0 */
    int iD8; unsigned char bDC, bDD, bDE; char pDF;
    int iE0, iE4; unsigned char bE8; char pE9[7];
    Plane floorPlane;             /* 0x0F0 */
    Face floorPoly;               /* 0x100 */
    Face waterPoly;               /* 0x170 */
    V v1E0;                       /* 0x1E0 */
    struct TR { void* e[3]; void Init(void* const& z) { int i = 0; goto t1; l1: e[(unsigned)i] = z; i++; t1: if (i <= 2) goto l1; } } tr;
    char p1FC[4];
    FA<QV, 3> anchorXf;           /* 0x200 */
    FA<QV, 3> prevXf;             /* 0x260 */
    char p2C0[4];
    float f2C4, f2C8; unsigned char b2CC; char p2CD[3];
    float f2D0; char p2D4[0xC];
    struct PM {
        char p0[0x10];
        V pm10, pm20, pm30, pm40, pm50, pm60; float pm70; char p354[0xC];
        void Init() {
            SetVF1(&pm10, 0.0f, 0.0f, 0.0f, 1.0f);
            SetVF1(&pm20, 0.0f, 0.0f, 0.0f, 1.0f);
            cVector_ctor_cVectorR(&pm30, cVector_GetZero());
            cVector_ctor_cVectorR(&pm40, cVector_GetZero());
            SetVF1(&pm50, 0.0f, 0.0f, 0.0f, 0.0f);
            SetVF1(&pm60, 0.0f, 0.0f, 0.0f, 0.0f);
            pm70 = 0.0f;
            cPointMass_SetMass(this, 75.0f);
        }
    } pm;                         /* 0x2E0 */
    V v360; float f370, f374; char p378[8];
    V v380; float f390, f394; char p398[8];
    FA<V, 3> offsets;             /* 0x3A0 */
    unsigned char b3D0; B2 b3D1[2]; char p3D5[0xB];
    char ledge[9][0xA0];          /* 0x3E0 */
    V ladder; float f990, f994, f998; struct ST { unsigned char e[10]; void Init(const unsigned char& v) { int i = 0; goto t2; l2: e[(unsigned)i] = v; i++; t2: if (i <= 9) goto l2; } } st; char p9A6; unsigned char b9A7; char p9A8[8];
    V v9B0; unsigned char b9C0; char p9C1[0xF];
    V v9D0;
    struct Fl { void* vt; char p[0xC]; V n; void Init() { Fl* t = this; t->vt = D_004DA810; t->vt = D_004DA800; t->n = V(0.0f, 0.0f, 1.0f, 0.0f); } };
    struct Le { void* vt; char p[0xC]; V d; void Init() { Le* t = this; t->vt = D_004DA810; t->vt = D_004DA820; t->d = V(1.0f, 0.0f, 0.0f, 0.0f); } };
    struct DPM { Fl fl; Le le; void Init() { DPM* t = this; t->fl.Init(); t->le.Init(); } } dpm;
    float fA20;
};

extern "C" R* cHumanCollisionRoutine_ctor(R* r)
{
    r->vtable = D_004DA330;
    r->vtable = D_004DAD00;
    r->gobj = 0;
    r->skel = 0;
    r->anim = 0;
    r->b10 = 0;
    r->b11 = 1;
    r->b12 = 1;
    r->b13 = 1;
    r->b14 = 1;
    { char* m = r->modes[0]; cModeSwitch_12_ctor_uint(m, 0); cModeSwitch_12_ctor_uint(m + 8, 0); cModeSwitch_12_ctor_uint(m + 16, 0); }
    { int* m = r->m30; func_001EC310(m, 0); func_001EC310(m + 1, 0); func_001EC310(m + 2, 0); }
    r->q40[0] = 0.0f; r->q40[1] = 0.0f; r->q40[2] = 0.0f; r->q40[3] = 1.0f;
    r->v50[0] = 0.0f; r->v50[1] = 0.0f; r->v50[2] = 0.0f; r->v50[3] = 0.0f; r->f60 = 0.0f;
    r->q70[0] = 0.0f; r->q70[1] = 0.0f; r->q70[2] = 0.0f; r->q70[3] = 1.0f;
    r->v80[0] = 0.0f; r->v80[1] = 0.0f; r->v80[2] = 0.0f; r->v80[3] = 0.0f; r->f90 = 0.0f;
    r->spl.Init();
    r->iD8 = 0;
    r->bDC = 0; r->bDD = 1; r->bDE = 0;
    r->iE0 = 0xFF7FFFFF; r->iE4 = 0xFF7FFFFF;
    r->bE8 = 0;
    r->floorPlane.Init(UnitQ(), V(0.0f, 0.0f, 1.0f, 0.0f));
    r->floorPoly.Init();
    r->waterPoly.Init();
    r->v1E0 = GetZero();
    r->tr.Init(0);
    r->anchorXf.Init(Ident());
    r->prevXf.Init(Ident());
    r->f2C4 = 0.0f; r->f2C8 = 0.0f; r->b2CC = 0; r->f2D0 = 0.0f;
    r->pm.Init();
    r->v360 = V(0.0f, 0.0f, 3.0f, 0.0f);
    r->f370 = D_004A03E0;
    r->f374 = D_004A03E0;
    r->v380 = D_004A03F0;
    r->f390 = 1.0f;
    r->f394 = 0.0f;
    r->offsets.Init(GetZero());
    r->b3D0 = 1;
    { B2* p = r->b3D1; B2* e = p + 2; do { p->Init(); ++p; } while (p != e); }
    __construct_array(r->ledge, (void*)cHumanCollisionRoutine_cFinalLedgeSearchInfo_ctor, (void*)cHumanCollisionRoutine_cFinalLedgeSearchInfo_dtor, 0xA0, 9);
    r->ladder = Unit();
    r->f990 = 0.0f; r->f994 = 0.0f; r->f998 = 0.0f;
    r->st.Init(D_0048A990);
    r->b9A7 = 0;
    r->v9B0 = GetZero();
    r->b9C0 = 0;
    r->v9D0 = GetZero();
    r->dpm.Init();
    r->fA20 = 0.0f;
    return r;
}
static inline void merge_flush_func_001EB990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB990 */
