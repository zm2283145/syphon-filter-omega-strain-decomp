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