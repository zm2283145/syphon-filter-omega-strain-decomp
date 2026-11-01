/* cHumanCollisionRoutine::UpdateClimbingEdge(cSystem&, const cArray<cCollisionFace>&) (humanCollision.cc) */
/* Inline asm here is limited to EE instructions C cannot express: 128-bit lq/sq quadword copies,
   VU0 macro-mode vector ops (lqc2/sqc2/vadd/vsub/vmul/...), and FPU abs.s/min.s/max.s. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, short) { const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(this) } }
    V& SetW(float ww) { w = ww; return *this; }
    V& SetZ(float zz) { z = zz; return *this; }
    float Dot(const V& o) const;
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));

static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline void MulT(V* d, const V* p, float s) { const V* pa = p; __int128 t = 0; V* pd = d; asm volatile { .set noreorder; lqc2 vf1, 0(pa); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(pd); .set reorder } }
static inline void AddT(V* d, const V* p, const V* q) { V* pd = d; const V* pa = p; const V* pb = q; asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pd) } }
static inline void SubT(V* d, const V* p, const V* q) { V* pd = d; const V* pa = p; const V* pb = q; asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pd) } }
static inline void NegT(V* d, const V* p) { asm volatile { lqc2 vf1, 0x0(p); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(d) } }
static inline V Mul0(const V& v, float s) { V r; MulT(&r, &v, s); return r; }
static inline V Add0(const V& a, const V& b) { V r; AddT(&r, &a, &b); return r; }
static inline V Sub0(const V& a, const V& b) { V r; SubT(&r, &a, &b); return r; }
static inline V Neg0(const V& a) { V r; const V* pa = &a; NegT(&r, pa); return r; }
static inline V Mul1(const V& v, float s) { return Mul0(v, s); }
static inline V Add1(const V& a, const V& b) { return Add0(a, b); }
static inline V Sub1(const V& a, const V& b) { return Sub0(a, b); }
static inline V Neg1(const V& a) { return Neg0(a); }
static inline V Sub2(const V& a, const V& b) { return Sub1(a, b); }
static inline V Sub3(const V& a, const V& b) { return Sub2(a, b); }
static inline V Sub4(const V& a, const V& b) { return Sub3(a, b); }
static inline V Sub5(const V& a, const V& b) { return Sub4(a, b); }
static inline void MulTP(V* d, const V* p, float s) { const V* pa = p; V* pd = d; __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(pa); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(pd); .set reorder } }
static inline V MulP0(const V& v, float s) { V r; MulTP(&r, &v, s); return r; }
static inline V MulP1(const V& v, float s) { return MulP0(v, s); }
static inline V MulP2(const V& v, float s) { return MulP1(v, s); }
static inline V AddG0(const V& a, const V& b) { V r; AddT(&r, &a, &b); return V(r, (short)0); }
static inline V AddG1(const V& a, const V& b) { return AddG0(a, b); }
static inline V AddG2(const V& a, const V& b) { return AddG1(a, b); }
struct VP { const V& v; VP(const V& x) : v(x) {} };
static inline V operator*(const V& v, float s) { return Mul1(v, s); }
static inline V operator+(const V& a, const V& b) { return Add1(a, b); }
static inline V operator-(const V& a, const V& b) { return Sub1(a, b); }
static inline V operator-(const V& a) { return Neg1(a); }
static inline void Normalize3(V* a)
{
    asm volatile {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(a)
    }
}
static inline float Dot(const V& aa, const V& bb)
{
    const V* a = &aa;
    const V* b = &bb;
    int rv0;
    float ret = 0.0f;
    asm volatile {
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
static inline float DotW1(const V& a, const V& b) { return Dot(a, b); }
static inline float DotW2(const V& a, const V& b) { return DotW1(a, b); }
static inline float DotW3(const V& a, const V& b) { return DotW2(a, b); }
static inline float DotW4(const V& a, const V& b) { return DotW3(a, b); }
static inline float DotW5(const V& a, const V& b) { return DotW4(a, b); }
inline float V::Dot(const V& o) const { return DotW3(*this, o); }
static inline V Lerp(const V& a, const V& b, float t)
{
    V r;
    V* d = &r;
    const V* p = &a;
    const V* q = &b;
    int tt;
    asm volatile {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(q)
        mfc1 tt, t
        qmtc2.ni tt, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(d)
    }
    return r;
}
static inline V QLerpN(const V& a, const V& b, float t)
{
    V r;
    V* d = &r;
    const V* p = &a;
    const V* q = &b;
    int tt;
    asm volatile {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(q)
        mfc1 tt, t
        qmtc2.ni tt, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(d)
    }
    return r;
}

struct cQuatVec;
struct cMatrix {
    V r0, r1, r2, r3;
    cMatrix() {}
    cMatrix(const cQuatVec& q);
    const V& GetAxis(int i) const { return (&r0)[i]; }
} __attribute__((aligned(16)));
struct cQuatVec {
    V rot; V pos;
    cQuatVec(const V& q, const V& p) : rot(q), pos(p) {}
};
extern "C" {
const V* cQuatVec_Rotation(const cQuatVec*);
const V* cQuatVec_Translation(const cQuatVec*);
cMatrix* cMatrix_ctor_cQuaternionR(cMatrix*, const V*);
void cMatrix_Set_cMatrixR_cVectorR(cMatrix*, const cMatrix*, const V*);
}
static inline void MSet0(cMatrix* m, const cQuatVec& q) { cMatrix t; cMatrix_Set_cMatrixR_cVectorR(m, cMatrix_ctor_cQuaternionR(&t, cQuatVec_Rotation(&q)), cQuatVec_Translation(&q)); }

struct cBitArray {
    int chunks[1];
    cBitArray() {}
    void Copy(const cBitArray& o) { for (int i = 0; i < 1; i++) chunks[i] = o.chunks[i]; }
    cBitArray(const cBitArray& o) { Copy(o); }
    void ClearAll() { for (int i = 0; i < 1; i++) chunks[i] = 0; }
    int Test(int i) const { return (chunks[i >> 5] >> (i & 31)) & 1; }
    void Set(int i) { chunks[i >> 5] |= 1 << (i & 31); }
};
struct tEdgeFlags {
    unsigned char m_flags;
    tEdgeFlags() {}
    tEdgeFlags(unsigned char f) : m_flags(f) {}
    tEdgeFlags(const tEdgeFlags& o) : m_flags(o.m_flags) {}
    unsigned char IsLadder() const { return (m_flags & 1) != 0; }
    int Type() const { return (m_flags >> 1) & 7; }
    int Side() const { return (m_flags >> 5) & 3; }
};
struct cCollisionEdge {
    V mVertex0;
    V mVertex1;
    V mVertexOnFaceButNotOnEdge;
    tEdgeFlags edgeFlags;
    float mLength;
    V mUnitEdgeVector;
    int edgeLocator[4];
    const V& UnitEdgeVector() const { return mUnitEdgeVector; }
};
struct EdgeVec;
struct cCollisionEdge;
struct cEdgeGroup { char pad[0x10]; void PushBack(const cCollisionEdge* const& v); };
struct EdgeGroupVec;
struct cCollisionFaceArray;
struct It { cCollisionEdge* p; It() {} It(const It& o) : p(o.p) {} };
struct ConstIterator {
    const cCollisionEdge* p;
    ConstIterator() {}
    ConstIterator(It i) : p(i.p) {}
    bool operator==(const ConstIterator& o) const { const cCollisionEdge* q = o.p; return p == q; }
    bool operator!=(const ConstIterator& o) const { return !(*this == o); }
    ConstIterator& operator++() { p++; return *this; }
    const cCollisionEdge& operator*() const { return *p; }
    const cCollisionEdge* operator->() const { return p; }
};
struct GIt { cEdgeGroup* p; };
struct CIt { const cCollisionEdge* p; };

struct cSkaAnimAnchor { char pad[0xD0]; float weight; float GetWeight() const { return weight; } };
extern "C" {
cSkaAnimAnchor* RootCollection_FindByKey(void*, const void*);
const cQuatVec* cSkaAnimAnchor_GetTransform(const cSkaAnimAnchor*);
const cQuatVec* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(const cSkaAnimAnchor*);
}
struct cSkaSystem { char pad[0xB0]; char anchors[4]; cSkaAnimAnchor& Find(const void* n) { return *RootCollection_FindByKey(anchors, n); } };
struct NodeC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char p4[0xC]; cMatrix mtx; unsigned char dirty;
    const cMatrix& GetMatrix() { if (dirty) Update(); return mtx; }
};
struct cSkeleton { char pad[0x28]; NodeC* node; };

struct cFinalLedgeSearchInfo {
    unsigned char mIsLedgeSearchRequested;
    unsigned char mOnlyReportFoundTypes;
    unsigned char mIsLedgeFound;
    char pad3[0xD];
    cCollisionEdge foundLedge;
    cBitArray mSubtypes;
    char pad74[0xC];
    V rot, pos;
    void Request(unsigned char only) { cFinalLedgeSearchInfo* t = this; if (t->mIsLedgeSearchRequested) t->mOnlyReportFoundTypes = t->mOnlyReportFoundTypes & only; else t->mOnlyReportFoundTypes = only; t->mIsLedgeSearchRequested = 1; }
    void RequestX(unsigned char only) { if (mIsLedgeSearchRequested) mOnlyReportFoundTypes = mOnlyReportFoundTypes & only; else mOnlyReportFoundTypes = only; mIsLedgeSearchRequested = 1; }
    const cCollisionEdge& FoundLedge() const { return foundLedge; }
    void ResetResults() { mIsLedgeFound = 0; mSubtypes.ClearAll(); }
};
struct cLedgeValidator;
struct cIntermediateLedgeSearchInfo {
    char pad0[0x31];
    unsigned char mIsLedgeSearchRequested;
    unsigned char mClimbingEdgeFound;
    char pad33[0xE0 - 0x33];
    float mMaxZHeightSoFar;
    char padE4[0xC];
    void Reset(const cFinalLedgeSearchInfo& f) { mIsLedgeSearchRequested = f.mIsLedgeSearchRequested; mClimbingEdgeFound = 0; mMaxZHeightSoFar = -3.4028235e38f; }
};
struct cIntermediateLedgeSearchInfoList {
    int count; int pad[3];
    cIntermediateLedgeSearchInfo items[9];
    cIntermediateLedgeSearchInfo* Begin() { return items; }
    cIntermediateLedgeSearchInfo* End() { return items + count; }
};
struct cSingleResult { unsigned char mHaveTestsBeenPerformed; cBitArray mTestResults; void Init() { mHaveTestsBeenPerformed = 0; mTestResults.ClearAll(); } };
struct cLedgeValidator {
    cSingleResult mClimbUp;
    cSingleResult mClimbDown;
    const cCollisionFaceArray* mFaceList;
    cLedgeValidator(const cCollisionFaceArray& f) { cLedgeValidator* t = this; t->mClimbUp.Init(); t->mClimbDown.Init(); t->mFaceList = &f; }
};
struct cSystem;
struct cHumanCollisionRoutine;
template <class T, int N> struct FA { T e[N]; T& operator[](unsigned int i) { return e[i]; } };
struct States { unsigned char e[10]; void Init(const unsigned char& v) { int i = 0; goto t2; l2: e[(unsigned)i] = v; i++; t2: if (i <= 9) goto l2; } };

extern "C" {
extern cIntermediateLedgeSearchInfoList* g_HumanColPresetMgr;
extern EdgeGroupVec* g_HumanColBufA;
extern EdgeVec* g_HumanColBufB;
extern char D_004F4FE0[];
extern char D_004A03C8[];
extern char D_004A03D0[];
extern char D_004A03D8[];
extern float D_004A0410;
extern float D_004A0430;
extern const unsigned char D_0048A998;
void std_vector_deleter_cCollisionEdge_clear(EdgeVec*);
void cCollisionEdgeCollector_GetAngledEdgesFromFaceList(void*, EdgeVec*, const cCollisionFaceArray*);
void std_vector_deleter_cEdgeGroup_clear(EdgeGroupVec*);
void cArray_cCollisionEdge_Begin(CIt*, EdgeVec*);
void cArray_cCollisionEdge_End(CIt*, EdgeVec*);
void cArray_cEdgeGroup_Begin_void(GIt*, EdgeGroupVec*);
void cArray_cEdgeGroup_End_void(GIt*, EdgeGroupVec*);
cEdgeGroup* cArray_cEdgeGroup_Iterator_opMul(const GIt*);
const cCollisionEdge* cArray_cCollisionEdge_ConstIterator_opMul(const CIt*);
unsigned char cEdgeGroup_DoesEdgeBelong(cEdgeGroup*, const cCollisionEdge*);
void cEdgeGroup_Append(cEdgeGroup*, cEdgeGroup*);
void cArray_cCollisionEdgePtr_Clear(cEdgeGroup*);
void cArray_cCollisionEdgePtr_PushBackActual(cEdgeGroup*, const cCollisionEdge* const*);
void cArray_cEdgeGroup_Iterator_opInc(GIt*);
unsigned char cArray_cEdgeGroup_Iterator_opNe(const GIt*, const GIt*);
void cEdgeGroup_ctor_cCollisionEdgeP(cEdgeGroup*, const cCollisionEdge*);
void cArray_cEdgeGroup_PushBackActual(EdgeGroupVec*, const cEdgeGroup*);
void cEdgeGroup_dtor(cEdgeGroup*, int);
void cArray_cCollisionEdge_ConstIterator_opInc(CIt*);
unsigned char cArray_cCollisionEdge_ConstIterator_opNe(const CIt*, const CIt*);
int cArray_cEdgeGroup_Size(EdgeGroupVec*);
cEdgeGroup* cArray_cEdgeGroup_opIndex(EdgeGroupVec*, int);
unsigned char cArray_cCollisionEdgePtr_Empty(cEdgeGroup*);
cEdgeGroup* cArray_cEdgeGroup_Back(EdgeGroupVec*);
void cEdgeGroup_opAssign(cEdgeGroup*, cEdgeGroup*);
void cArray_cEdgeGroup_PopBack(EdgeGroupVec*);
cCollisionEdge* std_vector_imp_cCollisionEdge_begin(EdgeVec*);
cCollisionEdge* std_vector_imp_cCollisionEdge_end(EdgeVec*);
It std_vector_cCollisionEdge_pointer2iterator(EdgeVec*, cCollisionEdge* const&);
void cVector_opSub(V*, const V*, const V*);
float cVector_Dot(const V*, const V*);
void cVector_opMul(V*, const V*, float);
void cVector_opAdd(V*, const V*, const V*);
void cVector_opAssign(V*, const V*);
void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_RecordLedge(cIntermediateLedgeSearchInfo*, cLedgeValidator&, cBitArray, const cCollisionEdge&, const V&, const V&, const V&, float, const V&, unsigned char, unsigned char);
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_RecordResults(cFinalLedgeSearchInfo*, cIntermediateLedgeSearchInfo*, EdgeGroupVec*);
void cHumanCollisionRoutine_DetermineIfHasReachedTopOfLadder(cHumanCollisionRoutine*);
void cHumanCollisionRoutine_DetermineIfHasReachedBottomOfLadder(cHumanCollisionRoutine*);
void ActorPhys_SelectEdgeRequest(cHumanCollisionRoutine*, cSystem*);
}

struct cHumanCollisionRoutine {
    void* vt;
    void* mGobj;
    cSkeleton* skeleton;
    cSkaSystem* animationSystem;
    char p10[0x20 - 0x10];
    int mMode;
    int mModeBits;
    char p28[0xDC - 0x28];
    unsigned char isInAir;
    unsigned char bDD;
    unsigned char bDE;
    char pDF[0x310 - 0xDF];
    V pmV30;
    char p320[0x394 - 0x320];
    float f394;
    char p398[0x3E0 - 0x398];
    FA<cFinalLedgeSearchInfo, 9> mFinalLedgeSearchInfoList;
    V baseLadderPoint;
    float ladderTopZ;
    float ladderMiddleZ;
    float ladderBottomZ;
    States ladderStates;
    char p9A6[0xA10 - 0x9A6];
    V mLedgeDir;
    bool IsModeBit(int i) const { return (mModeBits >> i) & 1; }
    bool IsLadderMode() const { return IsModeBit(9); }
    bool NotLadder() const { return !IsLadderMode(); }
    bool NotInAir() const { return !isInAir; }
    bool NotDE() const { return !bDE; }
};

inline void cEdgeGroup::PushBack(const cCollisionEdge* const& v) { const cCollisionEdge* const* pv = &v; cArray_cCollisionEdgePtr_PushBackActual(this, pv); }
static inline void MSet1(cMatrix* m, const cQuatVec& q) { MSet0(m, q); }
static inline void MSet2(cMatrix* m, const cQuatVec& q) { MSet1(m, q); }
static inline void MSet3(cMatrix* m, const cQuatVec& q) { MSet2(m, q); }
static inline void MSet4(cMatrix* m, const cQuatVec& q) { MSet3(m, q); }
inline cMatrix::cMatrix(const cQuatVec& q) { MSet4(this, q); }
static inline void NewGroup0(EdgeGroupVec& l, const cCollisionEdge* e)
{
    cEdgeGroup ng;
    cEdgeGroup_ctor_cCollisionEdgeP(&ng, e);
    cArray_cEdgeGroup_PushBackActual(&l, &ng);
    cEdgeGroup_dtor(&ng, -1);
}
static inline void NewGroup1(EdgeGroupVec& l, const cCollisionEdge* e) { NewGroup0(l, e); }
static inline void NewGroup2(EdgeGroupVec& l, const cCollisionEdge* e) { NewGroup1(l, e); }
static inline void GroupEdges(EdgeGroupVec& edgeGroupList, EdgeVec& edgeList)
{
    CIt currEdge; cArray_cCollisionEdge_Begin(&currEdge, &edgeList);
    CIt end; cArray_cCollisionEdge_End(&end, &edgeList);
    for (; cArray_cCollisionEdge_ConstIterator_opNe(&currEdge, &end); cArray_cCollisionEdge_ConstIterator_opInc(&currEdge)) {
        cEdgeGroup* group = 0;
        GIt g; cArray_cEdgeGroup_Begin_void(&g, &edgeGroupList);
        GIt gend; cArray_cEdgeGroup_End_void(&gend, &edgeGroupList);
        for (; cArray_cEdgeGroup_Iterator_opNe(&g, &gend); cArray_cEdgeGroup_Iterator_opInc(&g)) {
            cEdgeGroup* cg = cArray_cEdgeGroup_Iterator_opMul(&g);
            if (cEdgeGroup_DoesEdgeBelong(cg, cArray_cCollisionEdge_ConstIterator_opMul(&currEdge))) {
                if (!group) {
                    group = cg;
                } else {
                    cEdgeGroup_Append(group, cg);
                    cArray_cCollisionEdgePtr_Clear(cg);
                }
                group->PushBack(cArray_cCollisionEdge_ConstIterator_opMul(&currEdge));
            }
        }
        if (!group) NewGroup2(edgeGroupList, cArray_cCollisionEdge_ConstIterator_opMul(&currEdge));
    }
    for (int i = cArray_cEdgeGroup_Size(&edgeGroupList) - 1; i >= 0; i--) {
        if (cArray_cCollisionEdgePtr_Empty(cArray_cEdgeGroup_opIndex(&edgeGroupList, i))) {
            cEdgeGroup_opAssign(cArray_cEdgeGroup_opIndex(&edgeGroupList, i), cArray_cEdgeGroup_Back(&edgeGroupList));
            cArray_cEdgeGroup_PopBack(&edgeGroupList);
        }
    }
}

static inline It P2I(EdgeVec* v, cCollisionEdge* p) { cCollisionEdge* const& q = p; return std_vector_cCollisionEdge_pointer2iterator(v, q); }
static inline It EBegin(EdgeVec* v) { It r = P2I(v, std_vector_imp_cCollisionEdge_begin(v)); return r; }
static inline It EEnd(EdgeVec* v) { It r = P2I(v, std_vector_imp_cCollisionEdge_end(v)); return r; }

static inline void ProjectOntoEdge(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir)
{
    V a; cVector_opSub(&a, &v1, &v0);
    V b; cVector_opSub(&b, &point, &v0);
    V s; V m;
    float da = cVector_Dot(&a, &dir);
    float db = cVector_Dot(&b, &dir);
    if (da < 0.0f) { da = -da; db = -db; }
    if (db >= 0.0f && db <= da && da != 0.0f) {
        cVector_opMul(&m, &a, db / da);
        cVector_opAdd(&s, &v0, &m);
        cVector_opAssign(&out, &s);
        r = 1;
    } else r = 0;
}

static inline void GE1(EdgeGroupVec& a, EdgeVec& b) { GroupEdges(a, b); }
static inline void GE2(EdgeGroupVec& a, EdgeVec& b) { GE1(a, b); }
static inline void PE5(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir) { ProjectOntoEdge(r, out, point, v0, v1, dir); }
static inline void PE4(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir) { PE5(r, out, point, v0, v1, dir); }
static inline void PE1(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir) { PE4(r, out, point, v0, v1, dir); }
static inline void PE2(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir) { PE1(r, out, point, v0, v1, dir); }
static inline void PE3(bool& r, V& out, const V& point, const V& v0, const V& v1, const V& dir) { PE2(r, out, point, v0, v1, dir); }
static inline const V& Sel(unsigned char c, const V& a, const V& b) { return c ? a : b; }
static inline const V* SelP(unsigned char c, const V* a, const V* b) { return c ? a : b; }
static inline unsigned char A1(cHumanCollisionRoutine* s) { unsigned char r = 0; if (s->NotLadder() && s->NotInAir()) r = 1; return r; }
static inline unsigned char A2(cHumanCollisionRoutine* s) { unsigned char r = 0; if (A1(s) && s->NotDE()) r = 1; return r; }
static inline unsigned char A3(cHumanCollisionRoutine* s) { unsigned char r = 0; if (A2(s) && s->f394 <= 0.2f) r = 1; return r; }

static inline V AsPoint(const V& v) { V r = v; r.w = 1.0f; return r; }
static inline V Z0(V& r) { V* p = &r; p->z = 0.0f; return *p; }
/* quadword copy one inline level deeper than the copy ctor (keeps retail's register order) */
static inline void Cp0(V& d, const V& s) { V* pd = &d; const V* ps = &s; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
static inline void Cp1(V& d, const V& s) { Cp0(d, s); }
static inline V AsXY0(const V& v) { V r; Cp1(r, v); return Z0(r); }
static inline V AsXY1(const V& v) { return AsXY0(v); }
static inline V AsXY(const V& v) { return AsXY1(v); }
static inline V AsXY2(const V& v) { return AsXY(v); }
static inline V AsXY3(const V& v) { return AsXY2(v); }

extern "C" void cHumanCollisionRoutine_UpdateClimbingEdge(cHumanCollisionRoutine* self, cSystem& eventReceiver, const cCollisionFaceArray& faceList)
{
    if (self->IsModeBit(1)) {
        self->mFinalLedgeSearchInfoList[6].Request(0);
    }
    {
        unsigned char wasLedgeSearchRequested = 0;
        for (unsigned int i = 0; i < 9; i++) {
            self->mFinalLedgeSearchInfoList[i].ResetResults();
            wasLedgeSearchRequested = wasLedgeSearchRequested || self->mFinalLedgeSearchInfoList[i].mIsLedgeSearchRequested;
        }
        if ((self->mMode == 0 && wasLedgeSearchRequested) || self->IsModeBit(1) || self->mMode == 9) {
            EdgeGroupVec& edgeGroupList = *g_HumanColBufA;
            EdgeVec& edgeList = *g_HumanColBufB;
            std_vector_deleter_cCollisionEdge_clear(&edgeList);
            cCollisionEdgeCollector_GetAngledEdgesFromFaceList(D_004F4FE0, &edgeList, &faceList);
            std_vector_deleter_cEdgeGroup_clear(&edgeGroupList);
            GE2(edgeGroupList, edgeList);
            {
                cIntermediateLedgeSearchInfo* currIntermediate = g_HumanColPresetMgr->Begin();
                cIntermediateLedgeSearchInfo* end = g_HumanColPresetMgr->End();
                cFinalLedgeSearchInfo* currFinal = self->mFinalLedgeSearchInfoList.e;
                for (; currIntermediate != end; currFinal++, currIntermediate++) {
                    currIntermediate->Reset(*currFinal);
                }
            }
            self->ladderTopZ = -3.4028235e38f;
            self->ladderBottomZ = 3.4028235e38f;
            self->ladderStates.Init(D_0048A998);
            unsigned char isReadyToGetOnLadder = A3(self);
            V floorAnchorFacing;
            V ladderAnchorFacing;
            V ladderAnchorPosition;
            V edgeDetectionRefPos;
            V edgeDetectionRefPos_PlusOffset;
            if (!self->IsModeBit(9)) {
                float k = 0.1f;
                cSkaAnimAnchor& floorAnchor = self->animationSystem->Find(D_004A03C8);
                cMatrix floorAnchorMatrix(*cSkaAnimAnchor_GetTransform(&floorAnchor));
                floorAnchorFacing = self->skeleton->node->GetMatrix().GetAxis(1);
                edgeDetectionRefPos = floorAnchorMatrix.GetAxis(3);
                edgeDetectionRefPos_PlusOffset = edgeDetectionRefPos + self->pmV30 * k;
            } else {
                cSkaAnimAnchor& ledgeAnchor = self->animationSystem->Find(D_004A03D0);
                cSkaAnimAnchor& ladderAnchor = self->animationSystem->Find(D_004A03D8);
                float sumOfWeights = ledgeAnchor.GetWeight() + ladderAnchor.GetWeight();
                float lerpValue;
                if (sumOfWeights != 0.0f) lerpValue = ladderAnchor.GetWeight() / sumOfWeights;
                else lerpValue = 0.5f;
                cMatrix ladderAnchorMatrix(cQuatVec(
                    QLerpN(*cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ledgeAnchor)), *cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ladderAnchor)), lerpValue),
                    Lerp(*cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ledgeAnchor)), *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ladderAnchor)), lerpValue).SetW(1.0f)));
                ladderAnchorFacing = ladderAnchorMatrix.GetAxis(1);
                ladderAnchorPosition = ladderAnchorMatrix.GetAxis(3);
                edgeDetectionRefPos = ladderAnchorPosition;
                edgeDetectionRefPos_PlusOffset = edgeDetectionRefPos;
            }
            {
                ConstIterator currEdge = EBegin(&edgeList);
                ConstIterator end = EEnd(&edgeList);
                for (; currEdge != end; ++currEdge) {
                    tEdgeFlags edgeFlags; edgeFlags.m_flags = currEdge->edgeFlags.m_flags;
                    unsigned char isLadderEdge = edgeFlags.IsLadder();
                    const V& vertex0 = currEdge->mVertex0;
                    const V& vertex1 = currEdge->mVertex1;
                    const V& unitEdgeVector = currEdge->mUnitEdgeVector;
                    if (!(Abs(unitEdgeVector.z) <= 0.70700002f)) continue;
                    V unitEdgeXYVector = unitEdgeVector;
                    unitEdgeXYVector.z = 0.0f;
                    Normalize3(&unitEdgeXYVector);
                    V currStartPointProjectedOnEdge;
                    V currClimbPoint;
                    cBitArray ledgeSubtypes;
                    ledgeSubtypes.ClearAll();
                    if (isLadderEdge) {
                        ledgeSubtypes.Set(12);
                        if (isReadyToGetOnLadder) {
                            float ledgeHeightZ = vertex0.z - edgeDetectionRefPos.z;
                            if (edgeFlags.Type() == 3 && ledgeHeightZ > -0.75f && ledgeHeightZ < 0.75f) {
                                ledgeSubtypes.Set(15);
                            } else if (edgeFlags.Type() == 2 && ledgeHeightZ > -0.75f + D_004A0430 && ledgeHeightZ < 0.75f + D_004A0430) {
                                ledgeSubtypes.Set(14);
                            } else if (edgeFlags.Type() == 1 && ledgeHeightZ > -0.75f && ledgeHeightZ < 0.75f) {
                                ledgeSubtypes.Set(13);
                            } else {
                                ledgeSubtypes.Set(18);
                            }
                        } else {
                            ledgeSubtypes.Set(18);
                        }
                    }
                    float ledgeExtensionDistance;
                    if (ledgeSubtypes.Test(14)) ledgeExtensionDistance = 2.0f;
                    else if (ledgeSubtypes.Test(15)) ledgeExtensionDistance = 3.5f;
                    else if (ledgeSubtypes.Test(13)) ledgeExtensionDistance = 2.5f;
                    else ledgeExtensionDistance = 0.0f;
                    V extension = unitEdgeVector * ledgeExtensionDistance;
                    V vertex0Extended = vertex0 - extension;
                    V vertex1Extended = vertex1 + extension;
                    bool found; PE3(found, currStartPointProjectedOnEdge, Sel(isLadderEdge, edgeDetectionRefPos, edgeDetectionRefPos_PlusOffset), vertex0Extended, vertex1Extended, unitEdgeXYVector); unsigned char intersectionFound = found;
                    currClimbPoint = currStartPointProjectedOnEdge;
                    if (!intersectionFound) continue;
                    if (self->IsModeBit(9)) {
                        if (!isLadderEdge) continue;
                        unsigned char isEdgeNearCoplanarToXZPlaneOfLadderAnchorTransform = Abs(DotW4(Sub3(vertex0, ladderAnchorPosition), ladderAnchorFacing)) < 0.5f;
                        if (!isEdgeNearCoplanarToXZPlaneOfLadderAnchorTransform) continue;
                        self->ladderTopZ = Max(self->ladderTopZ, currClimbPoint.z);
                        self->ladderBottomZ = Min(self->ladderBottomZ, currClimbPoint.z);
                        if (edgeFlags.m_flags & 0x10) self->ladderStates.e[9] = 1;
                        V currVectorToClimbPoint = currClimbPoint - edgeDetectionRefPos;
                        float currZHeight = currVectorToClimbPoint.z;
                        float currZHeight_Feet = currZHeight + D_004A0410;
                        float kEndExitsOvershootFudge = 1.0f;
                        float kSideExitUndershootFudge = 1.0f;
                        if (currZHeight > -0.75f - kEndExitsOvershootFudge && currZHeight < 0.75f) {
                            if (edgeFlags.Type() == 1) self->ladderStates.e[4] = 1;
                        } else if (currZHeight_Feet > -0.75f && currZHeight_Feet < kSideExitUndershootFudge + (0.75f + kEndExitsOvershootFudge)) {
                            if (edgeFlags.Type() == 2) {
                                if (currZHeight_Feet > -0.75f && currZHeight_Feet < 0.75f + kEndExitsOvershootFudge) self->ladderStates.e[2] = 1;
                            } else if (edgeFlags.Type() == 3) {
                                if (currZHeight_Feet > -0.75f && currZHeight_Feet < 0.75f + kSideExitUndershootFudge) {
                                    self->ladderStates.e[8] = 0;
                                    self->ladderStates.e[3] = 1;
                                    self->ladderMiddleZ = currClimbPoint.z;
                                    switch (edgeFlags.Side()) {
                                    case 0: self->ladderStates.e[7] = 1; break;
                                    case 1: self->ladderStates.e[5] = 1; break;
                                    case 2: self->ladderStates.e[6] = 1; break;
                                    case 3: self->ladderStates.e[5] = 1; self->ladderStates.e[6] = 1; break;
                                    }
                                }
                            } else if (edgeFlags.Type() == 4) {
                                if (currZHeight_Feet > -0.75f && currZHeight_Feet < 0.75f) {
                                    if (!self->ladderStates.e[3]) {
                                        self->ladderStates.e[8] = 1;
                                        switch (edgeFlags.Side()) {
                                        case 0: self->ladderStates.e[7] = 1; break;
                                        case 1: self->ladderStates.e[5] = 1; break;
                                        case 2: self->ladderStates.e[6] = 1; break;
                                        case 3: self->ladderStates.e[5] = 1; self->ladderStates.e[6] = 1; break;
                                        }
                                    }
                                }
                            }
                        }
                    } else if (self->mMode == 0 || self->IsModeBit(1)) {
                        V currVectorToClimbPoint = currClimbPoint - edgeDetectionRefPos;
                        float currZHeight = currVectorToClimbPoint.z;
                        float currDistFromClimbPoint = 0.0f;
                        V currLedgeXYPerpendicular = -AsXY(currVectorToClimbPoint);
                        if (isLadderEdge) {
                            if (ledgeSubtypes.Test(12)) {
                                currClimbPoint = MulP2(AddG2(vertex0, vertex1), 0.5f);
                                if (ledgeSubtypes.Test(14) || ledgeSubtypes.Test(15)) currClimbPoint.z += D_004A0410;
                                currVectorToClimbPoint = currClimbPoint - edgeDetectionRefPos;
                                currZHeight = currVectorToClimbPoint.z;
                            }
                        } else if (edgeFlags.m_flags & 4) {
                            ledgeSubtypes.Set(4);
                        }
                        cLedgeValidator ledgeValidator(faceList);
                        cIntermediateLedgeSearchInfo* curr = g_HumanColPresetMgr->Begin();
                        cIntermediateLedgeSearchInfo* end = g_HumanColPresetMgr->End();
                        for (int i = 0; curr != end; curr++, i++) {
                            cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_RecordLedge(curr, ledgeValidator, ledgeSubtypes, *currEdge, currLedgeXYPerpendicular, currStartPointProjectedOnEdge, currClimbPoint, currZHeight, floorAnchorFacing, self->isInAir, !isLadderEdge);
                        }
                    }
                }
            }
            {
                cIntermediateLedgeSearchInfo* currIntermediate = g_HumanColPresetMgr->Begin();
                cIntermediateLedgeSearchInfo* end = g_HumanColPresetMgr->End();
                cFinalLedgeSearchInfo* currFinal = self->mFinalLedgeSearchInfoList.e;
                for (; currIntermediate != end; currIntermediate++, currFinal++) {
                    cHumanCollisionRoutine_cFinalLedgeSearchInfo_RecordResults(currFinal, currIntermediate, &edgeGroupList);
                }
            }
            if (self->mMode == 9) {
                cHumanCollisionRoutine_DetermineIfHasReachedTopOfLadder(self);
                cHumanCollisionRoutine_DetermineIfHasReachedBottomOfLadder(self);
            }
            if (self->mFinalLedgeSearchInfoList[6].mIsLedgeFound) {
                self->mLedgeDir = self->mFinalLedgeSearchInfoList[6].FoundLedge().UnitEdgeVector();
            }
        }
    }
    ActorPhys_SelectEdgeRequest(self, &eventReceiver);
    for (unsigned int i = 0; i < 9; i++) self->mFinalLedgeSearchInfoList[i].mIsLedgeSearchRequested = 0;
}
