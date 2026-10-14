/*
 * main/ska: range (3 files, 003BA710-003BA760)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003BA710 */
#pragma push /* merge_units */
/* Zero the bone's translation and rotation accumulators. */
typedef struct { __int128 q; } Q_3BA710;
typedef struct { unsigned char pad[0x180]; Q_3BA710 accumT; Q_3BA710 accumR; } Bone_3BA710;

#pragma peephole off
#pragma opt_propagation off
void Bone_ResetAccumulators(Bone_3BA710* b)
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
void SkelNode_SetInverseBind(SBA730_* dst, MBA730_* src)
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
extern "C" char D_0055C9F0[];
extern "C" void SkelNode_AttachParent(SkelSA* n, void* parent)
{
    XfSA* xf;
    if (parent) {
        n->Attach(parent, 1);
    }
    xf = n->xf;
    Vec4SA v(xf->pos.x, xf->pos.y, xf->pos.z);
    v.w = 1.0f;
    n->SetPos(&v);
    n->SetName(D_0055C9F0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA760 */
