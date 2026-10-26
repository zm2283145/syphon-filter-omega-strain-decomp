#include "types.h"
#pragma cplusplus on
#pragma bool on
#include "alloc_guard.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3AB510;
typedef struct { V4_3AB510 r[4]; } M_3AB510;
typedef struct { int w[1]; } LIt_3AB510;

struct BIt_3AB510;
static inline bool BEq(const BIt_3AB510* a, const BIt_3AB510* b);
struct BIt_3AB510 {
    char* volatile p;
    BIt_3AB510(char* q) : p(q) {}
    BIt_3AB510(const BIt_3AB510& o) : p(o.p) {}
    bool operator==(const BIt_3AB510& o) const { return BEq(this, &o); }
    bool operator!=(const BIt_3AB510& o) const { return !(*this == o); }
    BIt_3AB510& operator++() { p += 0x1D0; return *this; }
};

static inline bool BEq(const BIt_3AB510* a, const BIt_3AB510* b) { char* bp = b->p; return a->p == bp; }
extern "C" char** std_vector_deleter_cBone_data_void(void* self);
extern "C" char D_004BCFD8[];

struct BVec_3AB510 {
    int x0;
    int size;
    char* data;
    BIt_3AB510 begin() { return BIt_3AB510(*std_vector_deleter_cBone_data_void(this)); }
    BIt_3AB510 end() { return BIt_3AB510(*std_vector_deleter_cBone_data_void(this) + size * 0x1D0); }
};

struct Out_3AB510 {
    virtual void v00(); virtual void v01();
    virtual void SetXform(M_3AB510* m); virtual void SetPos(void* p);
};

typedef struct {
    char pad0[0x18];
    BVec_3AB510 bones;
    char pad24[0x28 - 0x24];
    Out_3AB510* out;
} Skel_3AB510;

typedef struct {
    int a;
    int b;
} Pair_3AB510;

typedef struct {
    char pad0[0x10];
    V4_3AB510 quat;
    char tail[0x10];
} Root_3AB510;

typedef struct {
    char pad0[0x10];
    unsigned int count;
    float hist[4];
    char pad24[0x30 - 0x24];
    Skel_3AB510* skel;
    char ctl[0x7C - 0x34];
    int list[3];
    char chans[0x9C - 0x88];
    unsigned int npairs;
    Pair_3AB510* pairs;
    char padA4[0xB0 - 0xA4];
    Root_3AB510 root;
} AnimModel_3AB510;

extern "C" {
void AnimChannels_Update(void* ch, float dt, float inv);
void cLList_cSkaTransPlaybackPtr_Begin(LIt_3AB510* out, void* list);
void cLList_cSkaTransPlaybackPtr_End(LIt_3AB510* out, void* list);
int opNe_cLListIteratorR_cLListIteratorR_8(LIt_3AB510* a, LIt_3AB510* b);
int* cLListIterator_cSkaTransPlaybackPtr_opMul(LIt_3AB510* it);
void cLListIterator_cSkaTransPlaybackPtr_opInc(LIt_3AB510* it);
int cSkaTransPlayback_NextFrame(int e, void* key);
void cLList_cSkaTransPlaybackPtr_Remove(void* list, int* v);
void opDelete_cSkaTransPlaybackP_int_bool_charP_etc(int p, int pool, int flags, char* file, int line);
void Bone_ResetAccumulators(char* b);
void Bone_FinalizeTranslation(char* b);
void Bone_FinalizeRotation(char* b);
void RootCollection_Reset(Root_3AB510* r);
void AnimCtl_Update(void* ctl, void* m, float dt);
void SkelNode_AccumulateOutputs(Root_3AB510* r);
}

static inline void ResetAll_3AB510(BIt_3AB510 first, BIt_3AB510 last)
{
    for (; first != last; ++first)
        Bone_ResetAccumulators(first.p);
}

static inline void FinAll_3AB510(BIt_3AB510 first, BIt_3AB510 last)
{
    for (; first != last; ++first) {
        Bone_FinalizeTranslation(first.p);
        Bone_FinalizeRotation(first.p);
    }
}

static inline void CopyPairs_3AB510(Pair_3AB510* p, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++, p++) {
        p->b = p->a;
    }
}

static inline M_3AB510* QuatToMtx_3AB510(M_3AB510* a, V4_3AB510* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}

static inline void PurgeList_3AB510(int* list, void* key)
{
    LIt_3AB510 it;
    LIt_3AB510 e;
    cLList_cSkaTransPlaybackPtr_Begin(&it, list);
    cLList_cSkaTransPlaybackPtr_End(&e, list);
    while (opNe_cLListIteratorR_cLListIteratorR_8(&it, &e)) {
        if ((unsigned char)cSkaTransPlayback_NextFrame(*cLListIterator_cSkaTransPlaybackPtr_opMul(&it), key)) {
            int v = *cLListIterator_cSkaTransPlaybackPtr_opMul(&it);
            cLListIterator_cSkaTransPlaybackPtr_opInc(&it);
            cLList_cSkaTransPlaybackPtr_Remove(list, &v);
            opDelete_cSkaTransPlaybackP_int_bool_charP_etc(v, 0, 1, D_004BCFD8, 0x49A);
        } else {
            cLListIterator_cSkaTransPlaybackPtr_opInc(&it);
        }
    }
}

#pragma opt_rotateloops off
#pragma opt_unroll_loops off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void AnimModel_Update(AnimModel_3AB510* m, float dt)
{
    {
        unsigned int c = m->count;
        if (c < 4) {
            m->hist[c] = dt;
            m->count++;
        }
    }
    AnimChannels_Update(m->chans, dt, 1.0f / dt);
    PurgeList_3AB510(m->list, &m->count);
    {
        BIt_3AB510 it = BIt_3AB510(m->skel->bones.begin());
        BIt_3AB510 e = BIt_3AB510(m->skel->bones.end());
        for (; it != e; ++it) {
            Bone_ResetAccumulators(it.p);
        }
    }
    RootCollection_Reset(&m->root);
    AnimCtl_Update(m->ctl, &m->count, dt);
    {
        BIt_3AB510 it = BIt_3AB510(m->skel->bones.begin());
        BIt_3AB510 e = BIt_3AB510(m->skel->bones.end());
        for (; it != e; ++it) {
            Bone_FinalizeTranslation(it.p);
            Bone_FinalizeRotation(it.p);
        }
    }
    SkelNode_AccumulateOutputs(&m->root);
    {
        Skel_3AB510* sk = m->skel;
        Root_3AB510* r = &m->root;
        sk->out->SetPos(r->tail);
    }
    {
        Skel_3AB510* sk = m->skel;
        /* scheduling barrier: emits no code */
        asm { .set reorder }
        Root_3AB510* r = &m->root;
        V4_3AB510* q = &r->quat;
        M_3AB510 mtx;
        /* scheduling barrier: emits no code */
        asm { .set reorder }
        QuatToMtx_3AB510(&mtx, q);
        sk->out->SetXform(&mtx);
    }
    {
        unsigned int n = m->npairs;
        if (n) {
            CopyPairs_3AB510(m->pairs, n);
        }
    }
    {
        unsigned int c = m->count;
        if (c) {
            m->count = c - 1;
        }
    }
}



