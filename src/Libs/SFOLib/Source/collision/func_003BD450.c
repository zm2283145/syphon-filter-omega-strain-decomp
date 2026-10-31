#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/*PRAGMAS*/
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o, unsigned char) { const V* src = &o; void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, unsigned short) { void* xx = this; const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, unsigned long) { const V* src = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(src) : "memory"); }
    V(const V& o, signed char) { V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); }
    V(const V& o, int) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o, short) { V* d = this; const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(src) : "memory"); }
    V(const V& o, char) { const V* src = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(src) : "memory"); }
    V(const V& o, long) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& o, float) { __int128 t; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V(const V& a, const V& b, int) { V* r = this; const V* p = &a; const V* q = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(p), "r"(q) : "memory"); }
    V(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    void Set(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); void* xx = this; }

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
    V& Normalize() { V* p = this; void* xx = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return *this;
    }
    V Neg(const V& b) const;
    V Unit() const { V r = *this; r.Normalize(); return r; }
} __attribute__((aligned(16)));
static inline V SubI(const V& a, const V& b) { V c(a, b, 0); return V(c, 0L); }
static inline V operator-(V a, const V& b) { const V& a2 = a; return SubI(a2, b); }
static inline V& Nz1(V& v) { return v.Normalize(); }

static inline V SubF(const V& a, const V& b) { V c; const V* q = &b; V* r = &c; const V* p = &a; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(p), "r"(q) : "memory"); return c; }

static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "+f"(r) : "f"(x)); return r; }
static inline float Max(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
struct cBox { V mn; V mx; };
extern "C" {
void cBox_Empty(cBox* b);
void cBox_Include(cBox* b, const V* v);
void cBox_Grow(cBox* b, float f);
V cVector_opAdd(const V* a, const V* b);
}
struct Probe {
    unsigned char collisionFeature;
    char pad01[0xF];
    V collisionNormal;
    V collisionNormal_WorldSpace;
    V collisionFaceNormal_WorldSpace;
    V collisionPoint;
    V collisionPoint_WorldSpace;
    V collisionFaceLocator;
    V spherePath;
    V spherePath_WorldSpace;
    V spherePathDir;
    float spherePathSquared;
    cBox bbox;
    void* mFaceList;
    float sphereRadius;
    float sphereRadiusSquared;
    V sphereStartPos;
};
static inline void IncludeSum(cBox* b, const V* s, const V* p) { cBox_Include(b, &cVector_opAdd(s, p)); }
static inline void CalcBBoxA(Probe* self) { cBox_Empty(&self->bbox); cBox_Include(&self->bbox, &self->sphereStartPos); IncludeSum(&self->bbox, &self->sphereStartPos, &self->spherePath); cBox_Grow(&self->bbox, self->sphereRadius); }
static inline void CalcBBoxB(Probe* self) { cBox_Empty(&self->bbox); cBox_Include(&self->bbox, &self->sphereStartPos); cBox_Include(&self->bbox, &cVector_opAdd(&self->sphereStartPos, &self->spherePath)); cBox_Grow(&self->bbox, self->sphereRadius); }
static inline void CalcBBoxC(Probe* self) { CalcBBoxA(self); }
static inline void CalcBBoxD(Probe* self) { CalcBBoxB(self); }
static inline V Sub1(const V& a, const V& b) { return SubF(a, b); }
static inline V Sub2(const V& a, const V& b) { return Sub1(a, b); }
static inline V Sub3(const V& a, const V& b) { return Sub2(a, b); }
static inline V Sub4(const V& a, const V& b) { return Sub3(a, b); }
static inline V Sub5(const V& a, const V& b) { return Sub4(a, b); }
static inline V Sub6(const V& a, const V& b) { return Sub5(a, b); }
static inline V Add1(const V& a, const V& b) { return a + b; }
static inline V Add2(const V& a, const V& b) { return Add1(a, b); }
static inline V Add3(const V& a, const V& b) { return Add2(a, b); }
static inline V Add4(const V& a, const V& b) { return Add3(a, b); }
static inline V Add5(const V& a, const V& b) { return Add4(a, b); }
static inline V Add6(const V& a, const V& b) { return Add5(a, b); }
static inline V Mul1(const V& a, float b) { return a * b; }
static inline V Mul2(const V& a, float b) { return Mul1(a, b); }
static inline V Mul3(const V& a, float b) { return Mul2(a, b); }
static inline V Mul4(const V& a, float b) { return Mul3(a, b); }
static inline V Mul5(const V& a, float b) { return Mul4(a, b); }
static inline V Mul6(const V& a, float b) { return Mul5(a, b); }
static inline V Sub7(const V& a, const V& b, V c = V()) { const V* q = &b; V* r = &c; const V* p = &a; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(p), "r"(q) : "memory"); return c; }
static inline V Add7(const V& a, const V& b, V c = V()) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
static inline V Mul7(const V& a, float s, V c = V()) { __int128 t = 0; V* q = &c; const V* v = &a; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
static inline V Sub8(const V& a, const V& b) { return Sub7(a, b); }
static inline V Add8(const V& a, const V& b) { return Add7(a, b); }
static inline V Mul8(const V& a, float b) { return Mul7(a, b); }
extern "C" unsigned char cCollisionProbe_SphereSweptRay_TestLineSegment_IgnoringEndPoints(Probe* self, const V* edgeVertices);
unsigned char cCollisionProbe_SphereSweptRay_TestLineSegment_IgnoringEndPoints(Probe* self, const V* edgeVertices)
{
    V E = SubF(edgeVertices[1], edgeVertices[0]);
    V D = Sub8(self->sphereStartPos, edgeVertices[0]);
    float DdotD = D.Dot(D);
    float DdotE = D.Dot(E);
    float DdotP = D.Dot(self->spherePath);
    float EdotE = E.Dot(E);
    float EdotP = E.Dot(self->spherePath);
    float a = EdotP * EdotP - EdotE * self->spherePathSquared;
    float b = 2.0f * (DdotE * EdotP - DdotP * EdotE);
    float c = DdotE * DdotE + self->sphereRadiusSquared * EdotE - DdotD * EdotE;
    float bSqr_Minus_4ac = b * b - 4.0f * a * c;
    if (!(bSqr_Minus_4ac < 0.0f)) {
        if (!(0.0f == a)) {
            float root = Sqrt(bSqr_Minus_4ac);
            float oneOver2a = 0.5f / a;
            float t_Unclamped;
            if (a > 0.0f)
                t_Unclamped = oneOver2a * (-b - root);
            else
                t_Unclamped = oneOver2a * (-b + root);
            if (t_Unclamped < 1.0f) {
                float t_Mid = -b * oneOver2a;
                if (!(t_Mid <= 0.0f)) {
                    if (!(0.0f == EdotE)) {
                        float t = Max(0.0f, t_Unclamped);
                        float u = (DdotE + t * EdotP) / EdotE;
                        if (!(u < 0.0f) && u <= 1.0f) {
                            V t_Times_P = self->spherePath * t;
                            V u_Times_E = Mul8(E, u);
                            self->collisionFeature = 2;
                            self->spherePath = t_Times_P;
                            self->spherePathSquared = self->spherePath.Dot(self->spherePath);
                            CalcBBoxC(self);
V n = D + t_Times_P - u_Times_E; self->collisionNormal = Nz1(n);
                            self->collisionPoint = edgeVertices[0] + u_Times_E;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

