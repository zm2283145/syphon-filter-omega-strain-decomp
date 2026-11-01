/* cLedgeValidator::cSingleResult::Validate (humanCollision.cc) */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    /* tagged return copy: the source pointer register doubles as the lq/sq temp */
    V(const V& o, short) { const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(this) } }
    const float& operator[](int i) const { return (&x)[i]; }
} __attribute__((aligned(16)));

static inline void MulT(V* d, const V* p, float s) { __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
static inline V operator*(const V& v, float s) { V r; MulT(&r, &v, s); return r; }
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void NegM(V* d, const V* p) { asm volatile { lqc2 vf1, 0x0(p); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(d) } }
static inline void CrossM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(d) } }
static inline V operator+(const V& a, const V& b) { V r; const V* p = &a; AddM(&r, p, &b); return V(r, (short)0); }
static inline V operator-(const V& a) { V r; NegM(&r, &a); return V(r, (short)0); }
static inline V Cross(const V& a, const V& b) { V r; CrossM(&r, &a, &b); return V(r, (short)0); }

struct cBitArray {
    int chunks[1];
    void Clear() { for (int i = 0; i < 1; i++) chunks[i] = 0; }
    int Test(int i) const { return (chunks[i >> 5] >> (i & 31)) & 1; }
    void Set(int i) { chunks[i >> 5] |= 1 << (i & 31); }
};

struct cCollisionFace {
    V vertices[3];
    V unitNormal;
    unsigned char faceProperties[16];
    char pad50[0x20];
};

struct cCollisionProbe_Ray {
    unsigned char hit;
    char pad1[0xF];
    V collisionNormal;
    V collisionPoint;
    int loc[4];
    V rayVector;
    V rayStartPoint;
    unsigned char c60, c61, c62;
    int i64;
};

struct cArray {
    int pad0;
    int count;
    cCollisionFace* data;
};

struct ConstIterator {
    const cCollisionFace* p;
    ConstIterator() {}
    ConstIterator(const cCollisionFace* q) : p(q) {}
    ConstIterator(const ConstIterator& o) : p(o.p) {}
    bool operator==(const ConstIterator& o) const { const cCollisionFace* q = o.p; return p == q; }
    bool operator!=(const ConstIterator& o) const { return !(*this == o); }
    ConstIterator& operator++() { p++; return *this; }
    const cCollisionFace& operator*() const { return *p; }
};

struct cSingleResult {
    unsigned char mHaveTestsBeenPerformed;
    cBitArray mTestResults;
};

extern "C" {
extern signed char D_004F4FF8;
extern cCollisionProbe_Ray D_004F5000[7];
extern char D_004F4FE8[];
extern float D_004A03B0;
void __construct_array(void* p, void* ctor, void* dtor, int size, int n);
void __register_global_object(void* obj, void* dtor, void* rec);
void cCollisionProbe_Ray_defctor(void);
void* cCollisionProbe_Ray_dtor(void* p, short f);
void func_001EEBB0(void);
cCollisionProbe_Ray* cCollisionProbe_Ray_ctor(cCollisionProbe_Ray* p, const V& s, const V& d);
cCollisionProbe_Ray* cCollisionProbe_Ray_opAssign(cCollisionProbe_Ray* d, const cCollisionProbe_Ray* s);
int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_bool(cCollisionProbe_Ray* p, const cCollisionFace* f, int b);
cCollisionFace** std_vector_deleter_cCollisionFace_data_void(const cArray* a);
}

struct Ray {
    cCollisionProbe_Ray r;
    Ray() {}
    ~Ray() { cCollisionProbe_Ray_dtor(&r, -1); }
    cCollisionProbe_Ray* Ptr() const { return (cCollisionProbe_Ray*)&r; }
};
static inline void Assign(cCollisionProbe_Ray& d, const Ray& s) { cCollisionProbe_Ray_opAssign(&d, &s.r); }
static inline unsigned char Has(const unsigned char* p, int m) { return p[0] & m; }
static inline ConstIterator Begin(const cArray& a) { ConstIterator t(*std_vector_deleter_cCollisionFace_data_void(&a)); return t; }
static inline ConstIterator End(const cArray& a) { ConstIterator t(*std_vector_deleter_cCollisionFace_data_void(&a) + a.count); return t; }
static inline bool Detect(cCollisionProbe_Ray& p, const cCollisionFace& f) { cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_bool(&p, &f, 0); return p.hit; }

#define probe D_004F5000
static inline cCollisionProbe_Ray* RB1() { cCollisionProbe_Ray r; return &r; }
static inline cCollisionProbe_Ray* RB2() { return RB1(); }
static inline void SetP(cCollisionProbe_Ray& d, const V& s, const V& v) { cCollisionProbe_Ray r; cCollisionProbe_Ray_ctor(&r, s, v); cCollisionProbe_Ray_opAssign(&d, &r); cCollisionProbe_Ray_dtor(&r, -1); }
static inline void SetP2(cCollisionProbe_Ray& d, const V& s, const V& v) { SetP(d, s, v); }
static inline const V* Addr(const V& v) { return &v; }
#define SETP(i, S, D) { const V* ps; const V* pd; (ps = Addr(S), pd = Addr(D), SetP2(probe[i], *ps, *pd)); }

extern "C" cBitArray* cLedgeValidator_cSingleResult_Validate(cSingleResult* self, const V& ledgeInteractionPoint, const V& unitLedgeXYNormal, const V& unitLedgeVector, const cArray& faceList)
{
    if (!self->mHaveTestsBeenPerformed) {
        self->mTestResults.Clear();
        const V neg_unitLedgeVector = -unitLedgeVector;
        V forward = -unitLedgeXYNormal;
        V up(0.0f, 0.0f, 1.0f, 0.0f);
        const V& right = (Cross(forward, unitLedgeVector).operator[](2) <= 0.0f) ? unitLedgeVector : neg_unitLedgeVector;

        if (!D_004F4FF8) {
            __construct_array(probe, (void*)cCollisionProbe_Ray_defctor, (void*)cCollisionProbe_Ray_dtor, 0x70, 7);
            __register_global_object(0, (void*)func_001EEBB0, D_004F4FE8);
            D_004F4FF8 = 1;
        }
        SETP(0, ledgeInteractionPoint + forward * -0.25f + up * 2.0f + right * -1.0f, up * -4.0f);
        SETP(1, ledgeInteractionPoint + forward * -0.25f + up * 2.0f + right * 1.0f, up * -4.0f);
        float kBlockingFloorPreventingHanging_TestStartPointOffsetHeight = 2.0f;
        SETP(2, ledgeInteractionPoint + forward * -0.25f + up * kBlockingFloorPreventingHanging_TestStartPointOffsetHeight + right * 0.0f,
                             up * (-7.5f - kBlockingFloorPreventingHanging_TestStartPointOffsetHeight));
        SETP(3, ledgeInteractionPoint + forward * -2.0f + up * 2.0f + right * -1.0f, forward * 4.0f);
        SETP(4, ledgeInteractionPoint + forward * -2.0f + up * 2.0f + right * 1.0f, forward * 4.0f);
        SETP(5, ledgeInteractionPoint + forward * -2.0f + up * -2.0f + right * -1.0f, forward * 4.0f);
        SETP(6, ledgeInteractionPoint + forward * -2.0f + up * -2.0f + right * 1.0f, forward * 4.0f);

        for (ConstIterator curr = Begin(faceList), end = End(faceList); curr != end; ++curr) {
            const cCollisionFace& face = *curr;
            const unsigned char* properties = face.faceProperties;
            if (Has(properties, 0x80) || Has(properties, 0)) continue;
            if (!self->mTestResults.Test(0)) {
                if (Detect(probe[0], face)) {
                    self->mTestResults.Set(0); self->mTestResults.Set(1); self->mTestResults.Set(2);
                } else if (Detect(probe[1], face)) {
                    self->mTestResults.Set(0); self->mTestResults.Set(1); self->mTestResults.Set(2);
                }
            }
            if (!self->mTestResults.Test(2) || !self->mTestResults.Test(1)) {
                if (Detect(probe[2], face)) {
                    self->mTestResults.Set(2);
                    float sz = probe[2].rayStartPoint.z; float pz = probe[2].collisionPoint.z; if (sz - kBlockingFloorPreventingHanging_TestStartPointOffsetHeight - pz <= D_004A03B0)
                        self->mTestResults.Set(1);
                }
            }
            if (!self->mTestResults.Test(3)) {
                if (Detect(probe[3], face)) self->mTestResults.Set(3);
                else if (Detect(probe[4], face)) self->mTestResults.Set(3);
            }
            if (!self->mTestResults.Test(4)) {
                if (Detect(probe[5], face)) self->mTestResults.Set(4);
                else if (Detect(probe[6], face)) self->mTestResults.Set(4);
            }
        }
        self->mHaveTestsBeenPerformed = 1;
    }
    return &self->mTestResults;
}
