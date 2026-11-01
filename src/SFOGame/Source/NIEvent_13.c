/*
 * SFOGame/Source/NIEvent: 4 files, 0023D180-0023D290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023D180 */
#pragma push /* merge_units */
#include "types.h"
#include "NIEvent_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec);

/* Constructs an empty vector that owns its storage. */
NIEventOwnedVec* cArray_cFXKeyPtr_ctor(NIEventOwnedVec* self) {
    std_vector_imp_cFXKeyPtr_1_ctor(&self->vec);
    self->owned = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D180 */

/* merge_units: begin func_0023D1B0 */
#pragma push /* merge_units */
/* Constructs an empty vector. */
NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D1B0 */

/* merge_units: begin func_0023D1D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
#include "q4r.h"
#include "vc_copy.h"

/* Rebuilds the cached transform: row 3 takes the position, rows 0-2 are left as they were on the stack. */

typedef struct Q16 { __int128 q; } Q16;
typedef struct M64 { __int128 r[3]; Q16 t; } M64;

class Obj {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void Update(); /* 0x120 */
    virtual void v47(); virtual void v48();
    virtual unsigned char TestA(float dt); /* 0x12C */
    virtual unsigned char TestB(float dt); /* 0x130 */

    char pad04[0x5C];
    int state;          /* 0x60 */
    char pad64[0x7C];
    Q16 pos;            /* 0xE0 */
    M64 mtx;            /* 0xF0 */
};

extern "C" void cNIEventBase_UpdateAll(Obj* self, float dt)
{
    unsigned char a = self->TestA(dt);
    unsigned char b = self->TestB(dt);
    if (a || b) {
        if (self->state != 3) {
            M64 m; __int128 t; __int128 qa; M64* d; M64* s; __int128 qb; Q16* pt;
            pt = &m.t; t = VLoadF(&self->pos); s = &m; d = &self->mtx; VStoreN(pt, t);
            Q4COPY_N(d, s, qa, qb)
        }
        self->Update();
    }
}
static inline void merge_flush_func_0023D1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D1D0 */

/* merge_units: begin func_0023D290 */
#pragma push /* merge_units */
// cNIEventBase::UpdatePos(float) (NIEvent.cc). Inline nesting depth (Eval2->Eval1->Eval, At->At1->At0, Scl/Neg2 wrappers) controls MW's
// stack-temp order and register coloring; VP members (no ctor) + explicit do-while give the array-ctor loop on t=this.
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/*PRAGMAS*/
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    void Set128(const V& o) { V* d = this; __int128 t; __asm__("lq %0, 0x0(%0)" : "=r"(t) : "0"(&o)); void* xx = (void*)&o; __asm__("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    V Unit() const { V r = *this; r.Normalize(); return r; }
} __attribute__((aligned(16)));
static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "+f"(r) : "f"(x)); return r; }
static inline float Max(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
struct cBox { V mn; V mx; };
extern "C" {
void cBox_Empty(cBox* b);
void cBox_Include(cBox* b, const V* v);
void cBox_Grow(cBox* b, float f);
V cVector_opAdd(const V* a, const V* b);
}
struct VectorKey { float time; char pad[12]; V value; V inTangent; V outTangent; };
struct VKArray { int cap; int count; VectorKey* data; int f; VectorKey& operator[](int i) { return data[i]; } VectorKey& At0(int i) { VectorKey*& d = data; return d[i]; } VectorKey& At1(int i) { return At0(i); } VectorKey& At(int i) { return At1(i); } };
struct VP { float x, y, z, w; VP& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; } } __attribute__((aligned(16))); struct CP { VP pos; VP tan; };
struct cHermiteSpline {
    CP mControlPoints[2];
    cHermiteSpline(const V& p0, const V& t0, const V& p1, const V& t1) { cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2);  t->mControlPoints[0].pos = p0; t->mControlPoints[0].tan = t0; CP* b = &t->mControlPoints[1]; t->mControlPoints[1].pos = p1; b->tan = t1; }
};
extern "C" {
VectorKey* std_vector_VectorKey_opIndex(VKArray* v, unsigned int i);
CP* cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(const cHermiteSpline* s, unsigned int i);
const V* cHermiteSplineControlPoint_cVector_Position(const CP* c);
const V* cHermiteSplineControlPoint_cVector_Tangent(const CP* c);
V opMul(float f, const V* v);
}
static inline V operator*(float s, V v) { V* p = &v; return *p * s; }
static inline V Neg(const V& a) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a) : "memory"); return c; }
static inline V Eval(const cHermiteSpline* s, float t) {
    float t2 = t * t;
    float t3 = t2 * t;
    float h00 = 1.0f + (2.0f * t3 - 3.0f * t2);
    float h01 = -2.0f * t3 + 3.0f * t2;
    float h10 = t + (t3 - 2.0f * t2);
    float h11 = t3 - t2;
    return cVector_opAdd(&cVector_opAdd(&cVector_opAdd(&opMul(h00, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 0))), &opMul(h01, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 1)))), &opMul(h10, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 0)))), &opMul(h11, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 1))));
}
static inline V Scl(const V& v, float s) { return v * s; } static inline V Neg2(const V& a) { return Neg(a); } static inline V Eval1(const cHermiteSpline* s, float t) { return Eval(s, t); } static inline V Eval2(const cHermiteSpline* s, float t) { return Eval1(s, t); }
struct cNIEventBase {
    char gobj[0xAC];
    VKArray mPosKeys;
    int mPosORT;
    float mPosTime;
    char pad_c4[0x1C];
    V mPos;
};
extern "C" unsigned char cNIEventBase_UpdatePos(cNIEventBase* self, float timeStep) {
    int posKey = self->mPosKeys.count - 1;
    float posScalar;
    float timeSpan;
    int i;
    if (posKey == 0) return 0;
    posScalar = 0.0f;
    self->mPosTime += timeStep;
    for (i = 0; i < self->mPosKeys.count - 1; i++) {
        if (!(self->mPosTime < self->mPosKeys[i].time) && self->mPosTime < self->mPosKeys[i + 1].time) {
            timeSpan = self->mPosKeys[i + 1].time - self->mPosKeys[i].time;
            posKey = i;
            posScalar = (self->mPosTime - self->mPosKeys[i].time) / timeSpan;
            break;
        }
    }
    if (posKey == self->mPosKeys.count - 1) {
        if (self->mPosORT == -1) {
            self->mPosTime = self->mPosKeys[posKey].time;
            self->mPos = self->mPosKeys[posKey].value;
            return 1;
        }
        int ort = self->mPosORT;
        float leftOver = self->mPosTime - self->mPosKeys[posKey].time;
        self->mPosTime = leftOver + self->mPosKeys[ort].time;
        posKey = ort;
        self->mPosTime = self->mPosKeys[posKey].time;
        timeSpan = self->mPosKeys[posKey + 1].time - self->mPosKeys[posKey].time;
        posScalar = self->mPosTime / timeSpan;
    }
    cHermiteSpline PosSpline(self->mPosKeys.At(posKey).value, Scl(std_vector_VectorKey_opIndex(&self->mPosKeys, posKey)->outTangent, timeSpan), self->mPosKeys.At(posKey + 1).value, timeSpan * Neg2(std_vector_VectorKey_opIndex(&self->mPosKeys, posKey + 1)->inTangent));
    self->mPos.Set128(Eval2(&PosSpline, posScalar));
    self->mPos.w = 1.0f;
    bool ok = true;
    return ok;
}
static inline void merge_flush_func_0023D290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D290 */
