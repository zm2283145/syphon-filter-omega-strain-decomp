#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#pragma inline_depth(10)

struct cVector {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct cBone_SkeletonBBoxContribution {
    unsigned char isActive;
    unsigned char needsUpdate;
    char pad02[2];
    float radius;
    char pad08[8];
    cVector offset;
};

struct cBone { char pad[0x150]; cBone_SkeletonBBoxContribution skeletonBBoxContribution; char pad2[0x1D0 - 0x170]; };

struct cSkeletonBBoxContribution { int boneIndex; int pad4; float radius; int padC; cVector offset; };

struct BoneVec { int unk0; int count; cBone* data; };

struct cSkeleton {
    void* skeletonData;
    char boneScales[0x10];
    unsigned char isActive;
    char pad15[3];
    BoneVec boneList;
};

struct ContribVec;

// volatile: retail keeps every iterator in its stack slot (prototype locals at 0x90-0x9C)
struct WrapB {
    cBone* p;
    WrapB(cBone* q) : p(q) {}
    WrapB(const WrapB& o) : p(o.p) {}
};

struct WrapC {
    const cSkeletonBBoxContribution** volatile p;
    WrapC(const WrapC& o) : p(o.p) {}
};

struct Iterator {
    WrapB mIterator;
    Iterator(const WrapB& w) : mIterator(w) {}
    cBone* base() const { return mIterator.p; }
    bool operator==(const Iterator& o) const { return mIterator.p == o.base(); }
    bool operator!=(const Iterator& o) const { return !(*this == o); }
    Iterator& operator++() { mIterator.p++; return *this; }
    cBone* operator->() const { return mIterator.p; }
};

struct ConstIterator {
    WrapC mIterator;
    ConstIterator(const WrapC& w) : mIterator(w) {}
    const cSkeletonBBoxContribution** base() const { return mIterator.p; }
    bool operator==(const ConstIterator& o) const { return mIterator.p == o.base(); }
    bool operator!=(const ConstIterator& o) const { return !(*this == o); }
    ConstIterator& operator++() { mIterator.p++; return *this; }
    const cSkeletonBBoxContribution* operator*() const { return *mIterator.p; }
    const cSkeletonBBoxContribution* const& Ref() const { return *mIterator.p; }
    const cSkeletonBBoxContribution* Get() const { const cSkeletonBBoxContribution** q = mIterator.p; return *q; }
    const cSkeletonBBoxContribution* const* Ptr() const { return mIterator.p; }
    const cSkeletonBBoxContribution* const& Ref2() const { const cSkeletonBBoxContribution* const& x = *mIterator.p; return x; }
    const WrapC& W() const { return mIterator; }
    const cSkeletonBBoxContribution* const& RefL() const { return Ref(); }
    const cSkeletonBBoxContribution* const& RefLL() const { return RefL(); }
    const cSkeletonBBoxContribution* StarL() const { return **this; }
    const cSkeletonBBoxContribution* StarLL() const { return StarL(); }
};
extern "C" {
extern signed char D_004E1D88;
extern cVector D_004E1D90;
cBone** std_vector_deleter_cBone_data_void(BoneVec* v);
const cSkeletonBBoxContribution** std_vector_imp_cSkeletonBBoxContributionPtr_1_begin(ContribVec* v);
const cSkeletonBBoxContribution** std_vector_imp_cSkeletonBBoxContributionPtr_1_end(ContribVec* v);
WrapC std_vector_cSkeletonBBoxContributionPtr_pointer2iterator(ContribVec* v, const cSkeletonBBoxContribution** const& raw);
void cBone_SkeletonBBoxContribution_dtor(cBone_SkeletonBBoxContribution* s, int flag);
void* opNew_uint_voidP(int size, void* p);
void cBone_SkeletonBBoxContribution_ctor(cBone_SkeletonBBoxContribution* s, cVector* v, float r);
cVector* cVector_ctor_cVectorR(cVector* d, const cVector* s);
}

static inline void* operator new(unsigned int, void* p) { return p; }

static inline void QCopy(void* d, const void* s) { __int128 t; asm { .set noreorder
 lq t, 0(s)
 .set reorder
 .set noreorder
 sq t, 0(d)
 .set reorder
 } }

static inline void QCopy2(void* d, const void* s) { __int128 t; asm { lq t, 0(s)
 .set noreorder
 sq t, 0(d)
 .set reorder
 } }
static inline void QCopyM(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); asm { sq t, 0(d) } }
static inline void CCopy(void* d, const void* s) { *(__int128*)d = *(const __int128*)s; }
static inline void VA(void* d, const void* s) { __int128 t; asm volatile { lq t, 0(s)
 sq t, 0(d) } }
static inline void VB(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0(%1)" :: "r"(t), "r"(d) : "memory"); }
static inline void VC(void* d, const void* s) { __int128 t; asm volatile { lq t, 0(s) } *(__int128*)d = t; }
static inline void VD(void* d, const void* s) { __int128 t = *(const __int128*)s; asm volatile { sq t, 0(d) } }
static inline void VE(void* d, const void* s) { __int128 t; asm volatile { .set noreorder
 lq t, 0(s)
 .set reorder
 .set noreorder
 sq t, 0(d)
 .set reorder
 } }
static inline void VSet(cVector* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }

static inline const cVector& GetZeroF(float z)
{
    if (!D_004E1D88) {
        D_004E1D90.x = z;
        D_004E1D90.y = z;
        D_004E1D90.z = z;
        D_004E1D90.w = z;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
static inline const cVector& GetZero()
{
    if (!D_004E1D88) {
        float z = 0.0f;
        D_004E1D90.x = z;
        D_004E1D90.y = z;
        D_004E1D90.z = z;
        D_004E1D90.w = z;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}

static inline void InitContribF(cBone_SkeletonBBoxContribution* c, float z)
{
    c->isActive = 0;
    c->needsUpdate = 1;
    *(int*)&c->radius = 0;
    VA(&c->offset, &GetZeroF(z));
}
static inline void InitContrib(cBone_SkeletonBBoxContribution* c)
{
    c->isActive = 0;
    c->needsUpdate = 1;
    *(int*)&c->radius = 0;
    QCopy(&c->offset, &GetZero());
}

static inline WrapB BoneBegin(BoneVec* v) { return WrapB(*std_vector_deleter_cBone_data_void(v)); }
static inline WrapB BoneEnd(BoneVec* v) { return WrapB(*std_vector_deleter_cBone_data_void(v) + v->count); }
static inline WrapC CBegin(ContribVec* v) { return std_vector_cSkeletonBBoxContributionPtr_pointer2iterator(v, std_vector_imp_cSkeletonBBoxContributionPtr_1_begin(v)); }
static inline WrapC CEnd(ContribVec* v) { return std_vector_cSkeletonBBoxContributionPtr_pointer2iterator(v, std_vector_imp_cSkeletonBBoxContributionPtr_1_end(v)); }
static inline const cVector* OffRef(const cSkeletonBBoxContribution* c) { return &c->offset; }
static inline cBone** DataRef(BoneVec* v) { return &v->data; }
static inline cBone*& DataR(BoneVec& v) { return v.data; }
static inline cBone*& DataR2(BoneVec& v) { return DataR(v); }
static inline cBone*& DataR3(BoneVec& v) { return DataR2(v); }
static inline cBone** DataRef2(BoneVec* v) { return DataRef(v); }
static inline cBone* volatile* DataRefV(BoneVec* v) { return (cBone* volatile*)&v->data; }
static inline cBone& AtI(BoneVec* v, int i) { int o = i * (int)sizeof(cBone); return *(cBone*)((char*)*DataRefV(v) + o); }
static inline cBone& AtIr(BoneVec* v, const int& i) { int o = i * (int)sizeof(cBone); return *(cBone*)((char*)*DataRefV(v) + o); }
static inline void VAr(const void* s, void* d) { __int128 t; asm volatile { lq t, 0(s)
 sq t, 0(d) } }
static inline cBone* const& DataCR(const BoneVec& v) { return v.data; }

static inline void Construct(cBone_SkeletonBBoxContribution* s, const cVector& off, const float& r)
{
    s = (cBone_SkeletonBBoxContribution*)opNew_uint_voidP(0x20, s);
    if (s) {
        cVector t;
        cBone_SkeletonBBoxContribution_ctor(s, cVector_ctor_cVectorR(&t, &off), r);
    }
}

static inline cVector* CopyRet(cVector* d, const cVector* src) { V4Copy(d, src); return d; }

static inline void Reconstruct(cBone_SkeletonBBoxContribution* s, const cVector* src, float r)
{
    cVector offv;
    cVector* po = CopyRet(&offv, src);
    cVector& off = *po;
    cBone_SkeletonBBoxContribution_dtor(s, -1);
    s = (cBone_SkeletonBBoxContribution*)opNew_uint_voidP(0x20, s);
    if (s) {
        cVector t;
        cBone_SkeletonBBoxContribution_ctor(s, cVector_ctor_cVectorR(&t, &off), r);
    }
}


static inline cBone& BoneAt(BoneVec* v, int i) { return v->data[i]; }
static inline cBone& BoneAtR(BoneVec& v, int i) { return v.data[i]; }
static inline cBone& BoneAtP(BoneVec* v, int i) { cBone** pd = &v->data; return (*pd)[i]; }
static inline void ReC(cBone_SkeletonBBoxContribution* s, float r, const cVector& o) {
    cVector offv; VA(&offv, &o);
    cBone_SkeletonBBoxContribution_dtor(s, -1);
    s = (cBone_SkeletonBBoxContribution*)opNew_uint_voidP(0x20, s);
    if (s) { cVector t; cBone_SkeletonBBoxContribution_ctor(s, cVector_ctor_cVectorR(&t, &offv), r); }
}
static inline void ReD(cBone_SkeletonBBoxContribution* s, const cVector& o, float r) {
    cVector offv; VA(&offv, &o);
    cBone_SkeletonBBoxContribution_dtor(s, -1);
    s = (cBone_SkeletonBBoxContribution*)opNew_uint_voidP(0x20, s);
    if (s) { cVector t; cBone_SkeletonBBoxContribution_ctor(s, cVector_ctor_cVectorR(&t, &offv), r); }
}
extern "C" void cSkeleton_ResetBBoxContributors(cSkeleton* self, ContribVec* bboxContributors)
{
    if (0) { asm volatile { nop } } // less-optimised mode trigger
    if (self->isActive) {
        Iterator currBone(BoneBegin(&self->boneList));
        Iterator end(BoneEnd(&self->boneList));
        float z = 0.0f;
        for (; currBone != end; ++currBone) {
            cBone_SkeletonBBoxContribution* p = (cBone_SkeletonBBoxContribution*)operator new(0x20, &currBone->skeletonBBoxContribution);
            if (p) InitContribF(p, z);
        }
        ConstIterator currContribution(CBegin(bboxContributors));
        ConstIterator end2(CEnd(bboxContributors));
        for (; currContribution != end2; ++currContribution) {
            const int& idx = (*currContribution.base())->boneIndex;
            float r = (*currContribution)->radius;
            const cVector* src = &(*currContribution.base())->offset;
            cBone& currBone = AtI(&self->boneList, idx);
            cVector offv; VA(&offv, src); cVector& off = offv;
            cBone_SkeletonBBoxContribution* s = &currBone.skeletonBBoxContribution;
            cBone_SkeletonBBoxContribution_dtor(s, -1);
            s = (cBone_SkeletonBBoxContribution*)opNew_uint_voidP(0x20, s);
            if (s) {
                cVector t;
                cBone_SkeletonBBoxContribution_ctor(s, cVector_ctor_cVectorR(&t, &off), r);
            }
        }
    }
}
