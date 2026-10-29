#pragma cplusplus on
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));

struct Mask { int w[1]; };
struct Flags { unsigned char b; };
struct Range { float lo, hi; bool Contains(float v) const { bool r = false; if (!(v < lo) && v <= hi) r = true; return r; } };
struct Loc { int a, b, c, d; } __attribute__((aligned(16)));
struct Edge {
    V v0;            /* 00 */
    V v1;            /* 10 */
    V v2;            /* 20 */
    Flags flags;     /* 30 */
    float len;       /* 34 */
    V dir;           /* 40 */
    V loc;           /* 50 */
};
struct SingleResult { int a, b; };
struct LedgeValidator { SingleResult up; SingleResult down; void* faces; };

struct Info {
    signed char mDefaultSubtype;  /* 00 */
    Mask m4;                      /* 04 */
    Mask m8;                      /* 08 */
    Mask mC;                      /* 0C */
    Mask m10;                     /* 10 */
    Range zR;  /* 14 */
    Range dR;  /* 1C */
    Range cR;  /* 24 */
    unsigned char flip;           /* 2C */
    char pad2D[3];
    unsigned char mDetectForWhileInAir;   /* 30 */
    unsigned char mIsLedgeSearchRequested;/* 31 */
    unsigned char mClimbingEdgeFound;     /* 32 */
    Edge mClimbingEdge;           /* 40 */
    Mask mSubtypes;               /* A0 */
    V mPerp;                      /* B0 */
    V mStart;                     /* C0 */
    V mClimb;                     /* D0 */
    float mMaxZ;                  /* E0 */
    float mCos;                   /* E4 */
};

extern "C" {
int cBitArray_19_opAnd(Mask* out, Mask* a, Mask* b);
int cBitArray_19_opCompl(Mask* out, Mask* a);
bool cBitArray_19_opEq(Mask* a, Mask* b);
void* cBitArray_19_dtor(Mask* self, short flag);
int cBitArray_5_opAnd(Mask* out, Mask* a, Mask* b);
int cBitArray_5_opCompl(Mask* out, Mask* a);
bool cBitArray_5_opEq(Mask* a, Mask* b);
void* cBitArray_5_dtor(Mask* self, short flag);
V CalculateUnitEdgeOutwardXYNormal(const Edge* e);
Mask* cLedgeValidator_cSingleResult_Validate(SingleResult* r, const V& p, const V& n, const V& d, void* faces);
int cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(Mask* out, void* self, Mask* q);
void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_RecordLedge(Info* self, LedgeValidator& lv, Mask* subtypes,
    const Edge& edge, const V& xyPerp, const V& startPt, const V& climbPoint, float zHeight, const V& refDir,
    bool isInAir, bool doValidation);
}

static inline float Dot3(const V* a, const V* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline float Dot3b(const V* a, const V* b) {
    int rv0;
    int rv1;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv1, rv0, rv0
        mtc1 rv1, ret
    }
    return ret;
}
static inline float LenSq(const V* a) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}

static inline bool MaskEq(Mask* a, Mask* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a->w[i] != b->w[i]) return false;
    }
    return true;
}
static inline float Clamp(float x, float hi, float lo) { asm { max.s x, x, lo
 min.s x, x, hi } return x; }
static inline bool Eq2(Mask* a, Mask* b) { return MaskEq(a, b); }
static inline float MaxF(float x, float y) { asm { max.s x, x, y } return x; }
static inline float MinF(float x, float y) { asm { min.s x, x, y } return x; }
static inline float Clamp2(float x, float lo, float hi) { asm { max.s x, x, lo
 min.s x, x, hi } return x; }
static inline bool InRange(float v, float lo, float hi) { bool r = false; if (!(v < lo) && v <= hi) r = true; return r; }

void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_RecordLedge(Info* self, LedgeValidator& lv, Mask* subtypes,
    const Edge& edge, const V& xyPerp, const V& startPt, const V& climbPoint, float zHeight, const V& refDir,
    bool isInAir, bool doValidation)
{
    Mask r;
    Mask t1;
    Mask t2;
    bool m1;
    if (self->mIsLedgeSearchRequested) {
        cBitArray_19_opAnd(&t1, subtypes, &self->m4);
        m1 = MaskEq(&t1, &self->m4);
        if (m1) {
            Mask c1;
            Mask a1;
            bool ok1;
            cBitArray_19_opCompl(&c1, subtypes);
            cBitArray_19_opAnd(&a1, &c1, &self->m8);
            ok1 = cBitArray_19_opEq(&a1, &self->m8);
            cBitArray_19_dtor(&a1, -1);
            cBitArray_19_dtor(&c1, -1);
            if (ok1 && !(zHeight <= self->mMaxZ) && self->zR.Contains(zHeight)) {
                V n = CalculateUnitEdgeOutwardXYNormal(&edge);
                float cosAngle = Dot3b(&refDir, &n);
                if (!self->flip) cosAngle = -cosAngle;
                { float lo = -1.0f; float hi = 1.0f; cosAngle = Clamp2(cosAngle, lo, hi); }
                if (self->cR.Contains(cosAngle)) {
                    float xyDistSquared = LenSq(&xyPerp);
                    float d = xyDistSquared * (Dot3(&xyPerp, &n) > 0.0f ? 1.0f : -1.0f);
                    if (self->flip) d = -d;
                    if (self->dR.Contains(d) && (self->mDetectForWhileInAir || !isInAir)) {
                        unsigned char hasBeenValidated;
                        if (doValidation) {
                            Mask* testResults;
                            bool e;
                            int i;
                            const V& dir = edge.dir;
                            testResults = self->flip ? cLedgeValidator_cSingleResult_Validate(&lv.down, climbPoint, n, dir, lv.faces)
                                                     : cLedgeValidator_cSingleResult_Validate(&lv.up, climbPoint, n, dir, lv.faces);
                            cBitArray_5_opAnd(&t2, testResults, &self->mC);
                            e = MaskEq(&t2, &self->mC);
                            if (e) {
                                Mask c2;
                                Mask a2;
                                bool ok2;
                                cBitArray_5_opCompl(&c2, testResults);
                                cBitArray_5_opAnd(&a2, &c2, &self->m10);
                                ok2 = cBitArray_5_opEq(&a2, &self->m10);
                                cBitArray_5_dtor(&a2, -1);
                                cBitArray_5_dtor(&c2, -1);
                                e = ok2;
                            }
                            hasBeenValidated = e;
                            cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(&r, self, testResults);
                            for (i = 0; i < 1; i++) { int v = r.w[i]; subtypes->w[i] |= v; }
                        } else {
                            hasBeenValidated = 1;
                        }
                        if (hasBeenValidated) {
                            int i;
                            int b;
                            self->mClimbingEdgeFound = 1;
                            self->mClimbingEdge = edge;
                            for (i = 0; i < 1; i++) self->mSubtypes.w[i] = subtypes->w[i];
                            self->mPerp = n;
                            self->mStart = startPt;
                            self->mClimb = climbPoint;
                            self->mMaxZ = zHeight;
                            self->mCos = cosAngle;
                            b = self->mDefaultSubtype;
                            self->mSubtypes.w[b / 32] |= 1 << (b & 31);
                        }
                    }
                }
            }
        }
    }
}
