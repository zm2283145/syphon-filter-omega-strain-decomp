#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/*PRAGMAS*/
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");  }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    void Set(const V& o) {  __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); void* xx = this; }
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
    V& Normalize() { void* x3 = this; 
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); return *this; 
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
static inline void CalcBBox(Probe* self) { cBox_Empty(&self->bbox); cBox_Include(&self->bbox, &self->sphereStartPos); IncludeSum(&self->bbox, &self->sphereStartPos, &self->spherePath); cBox_Grow(&self->bbox, self->sphereRadius); }
extern "C" unsigned char cCollisionProbe_SphereSweptRay_TestPoint(Probe* self, const V& vertex);
unsigned char cCollisionProbe_SphereSweptRay_TestPoint(Probe* self, const V& vertex)
{
    V D = self->sphereStartPos - vertex;
    float DdotD = D.Dot(D);
    float DdotP = D.Dot(self->spherePath);
    float PdotP = self->spherePath.Dot(self->spherePath);
    float a = self->spherePathSquared;
    float b = 2.0f * DdotP;
    float c = DdotD - self->sphereRadiusSquared;
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
                    float t = Max(0.0f, t_Unclamped);
                    V t_Times_P = self->spherePath * t;
                    self->collisionFeature = 3;
                    self->spherePath = t_Times_P;
                    self->spherePathSquared = self->spherePath.Dot(self->spherePath);
                    CalcBBox(self);
                    V n = D + t_Times_P; self->collisionNormal.Set(n.Normalize());
                    
                    self->collisionPoint.Set(vertex);
                    return 1;
                }
            }
        }
    }
    return 0;
}



