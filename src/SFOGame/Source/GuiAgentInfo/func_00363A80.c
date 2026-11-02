#pragma cplusplus on
#include "types.h"
#pragma inline_depth(10)

/* Byte-identical clone of cSkeleton::ResetBBoxContributors (0x290610; prototype SCUS_973.97 0x27C1F0). */

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

struct WrapB {
    cBone* p;
    WrapB(cBone* q) : p(q) {}
    WrapB(const WrapB& o) : p(o.p) {}
};

struct WrapC {
    /* volatile: each use re-reads the iterator from its stack slot (prototype locals at 0x90-0x9C),
       in source order, as retail does */
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
    const cSkeletonBBoxContribution* Get() const { const cSkeletonBBoxContribution** q = mIterator.p; return *q; }
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

/* 128-bit cVector copy: lq/sq cannot be expressed in C here (a C-level 128-bit copy folds the
   address offsets and moves the load); volatile also keeps retail's less-optimised block shape. */
static inline void VA(void* d, const void* s) { __int128 t; asm volatile { lq t, 0(s)
 sq t, 0(d) } }

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

static inline void InitContribF(cBone_SkeletonBBoxContribution* c, float z)
{
    c->isActive = 0;
    c->needsUpdate = 1;
    *(int*)&c->radius = 0;
    VA(&c->offset, &GetZeroF(z));
}

static inline WrapB BoneBegin(BoneVec* v) { return WrapB(*std_vector_deleter_cBone_data_void(v)); }
static inline WrapB BoneEnd(BoneVec* v) { return WrapB(*std_vector_deleter_cBone_data_void(v) + v->count); }
static inline WrapC CBegin(ContribVec* v) { return std_vector_cSkeletonBBoxContributionPtr_pointer2iterator(v, std_vector_imp_cSkeletonBBoxContributionPtr_1_begin(v)); }
static inline WrapC CEnd(ContribVec* v) { return std_vector_cSkeletonBBoxContributionPtr_pointer2iterator(v, std_vector_imp_cSkeletonBBoxContributionPtr_1_end(v)); }

/* The bone-list data pointer is read through a volatile pointer: plain C, it keeps retail's load
   order (the data load sits between the iterator loads). The scaled index is computed first, which
   gives retail's register choice. */
static inline cBone* volatile* DataRefV(BoneVec* v) { return (cBone* volatile*)&v->data; }
static inline cBone& AtI(BoneVec* v, int i) { int o = i * (int)sizeof(cBone); return *(cBone*)((char*)*DataRefV(v) + o); }

extern "C" void FrontEnd_SetNodeSpheres_363A80(cSkeleton* self, ContribVec* bboxContributors)
{
    if (0) { asm volatile { nop } } // less-optimised mode trigger (owner-approved idiom, emits nothing)
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
            const cSkeletonBBoxContribution* pi = *currContribution;
            int idx = pi->boneIndex;
            const cSkeletonBBoxContribution* pr = currContribution.Get();
            float r = pr->radius;
            const cVector* src = &(*currContribution.base())->offset;
            cBone& currBone = AtI(&self->boneList, idx);
            cVector offv;
            VA(&offv, src);
            cVector& off = offv;
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
