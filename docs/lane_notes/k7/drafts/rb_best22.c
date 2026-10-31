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
    cBone* volatile p;
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
static inline void VSet(cVector* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }

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

#pragma opt_rotateloops off
extern "C" void cSkeleton_ResetBBoxContributors(cSkeleton* self, ContribVec* bboxContributors)
{
    if (self->isActive) {
        Iterator currBone(BoneBegin(&self->boneList));
        Iterator end(BoneEnd(&self->boneList));
        for (; currBone != end; ++currBone) {
            cBone_SkeletonBBoxContribution* p = (cBone_SkeletonBBoxContribution*)operator new(0x20, &currBone->skeletonBBoxContribution);
            if (p) InitContrib(p);
        }
        ConstIterator currContribution(CBegin(bboxContributors));
        ConstIterator end2(CEnd(bboxContributors));
        for (; currContribution != end2; ++currContribution) {
            int idx = (*currContribution)->boneIndex;
            float r = (*currContribution)->radius;
            cBone** pd = DataRef(&self->boneList);
            cVector offv;
            QCopy2(&offv, &(*currContribution)->offset);
            cVector& off = offv;
            cBone& currBone = (*pd)[idx];
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
