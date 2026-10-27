/*
 * Libs/SFOLib/Source/bone: 5 files, 003BA5F0-003BA7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BA5F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cBone_AnimationSetWeightedOffset: push the accumulated translation, or restore the bind position */
typedef struct Vec3BT { float x, y, z; } Vec3BT;
struct Vec4BT {
    float x, y, z, w;
    Vec4BT() {}
    Vec4BT(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
typedef struct XfBT { int a, b; Vec3BT pos; } XfBT;
struct BoneBT {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4BT* p);
    char pad[0xBC];
    XfBT* xf;
    char padC4[0x180 - 0xC4];
    Vec4BT accumT;
    Vec4BT accumR;
    char pad1A0[0x10];
    Vec4BT pos;
};
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline int IsZero(const Vec4BT* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
extern "C" void cBone_AnimationSetWeightedOffset(BoneBT* b)
{
    if (!IsZero(&b->accumT)) {
        b->accumT.w = 1.0f;
        b->SetPos(&b->accumT);
        VC(&b->pos, &b->accumT);
    } else if (IsZero(&b->pos)) {
        XfBT* xf = b->xf;
        Vec4BT* q;
        Vec4BT v(xf->pos.x, xf->pos.y, xf->pos.z);
        Vec4BT* p = &b->pos;
        VC(p, &v);
        q = &b->pos; q->w = 1.0f;
    }
}
static inline void merge_flush_func_003BA5F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA5F0 */

/* merge_units: begin func_003BA710 */
#pragma push /* merge_units */
/* Zero the bone's translation and rotation accumulators. */
typedef struct { __int128 q; } Q_3BA710;
typedef struct { unsigned char pad[0x180]; Q_3BA710 accumT; Q_3BA710 accumR; } Bone_3BA710;

#pragma peephole off
#pragma opt_propagation off
void cBone_AnimationClearAccumulation(Bone_3BA710* b)
{
    __int128* p;
    p = &b->accumT.q; *p = 0;
    p = &b->accumR.q; *p = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA710 */

/* merge_units: begin func_003BA730 */
#pragma push /* merge_units */
typedef struct { __int128 q[4]; } MBA730_;
typedef struct { char pad[0xD0]; MBA730_ m; } SBA730_;
#pragma peephole off
void cBone_SetMeshSpaceToBoneSpaceMatrix(SBA730_* dst, MBA730_* src)
{
    MBA730_* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA730 */

/* merge_units: begin func_003BA760 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Vec3SA { float x, y, z; } Vec3SA;
struct Vec4SA { float x, y, z, w; Vec4SA() {} Vec4SA(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; } };
typedef struct XfSA { int a, b; Vec3SA pos; } XfSA;
struct SkelSA {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4SA* p);
    virtual void v0E(); virtual void v0F();
    virtual void Attach(void* parent, int f);
    char pad[0xBC];
    XfSA* xf;
};
extern "C" char g_IdentityMatrix[];
extern "C" void cBone_SetParent(SkelSA* n, void* parent)
{
    XfSA* xf;
    if (parent) {
        n->Attach(parent, 1);
    }
    xf = n->xf;
    Vec4SA v(xf->pos.x, xf->pos.y, xf->pos.z);
    v.w = 1.0f;
    n->SetPos(&v);
    n->SetName(g_IdentityMatrix);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA760 */

/* merge_units: begin func_003BA7F0 */
#pragma push /* merge_units */
typedef struct { char data[0x1D0]; } SkelInit; /* temporary built from the record */
typedef struct { char pad[0xC0]; void* record; } SkelNode;
extern void cBone_ctor_void(SkelInit* init, void* record);
extern void cBone_opAssign(SkelNode* node, SkelInit* init);
extern void cBone_dtor(SkelInit* init, int flags);

/* Initializes the node from a record via a temporary init block, then remembers the record. */
void cBone_Init(SkelNode* self, void* record)
{
    SkelInit init;
    cBone_ctor_void(&init, record);
    cBone_opAssign(self, &init);
    self->record = record;
    cBone_dtor(&init, -1);
}
static inline void merge_flush_func_003BA7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA7F0 */
