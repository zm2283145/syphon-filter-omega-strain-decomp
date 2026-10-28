/*
 * SFOGame/Source/human: 5 files, 001AF600-001AF6B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AF600 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_propagation off
#pragma opt_common_subs off

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

/* cBone_SkeletonBBoxContribution (human.cc) */
typedef struct {
    unsigned char doesBoneContribute;
    unsigned char isOffsetZero;
    char pad02[2];
    float contributionPointRadius;
    char pad08[8];
    V contributionPointOffset;
} Obj1AF600;

static inline V AsPoint(const V& src) {
    asm { .set reorder } /* scheduling: ends the noreorder region the VU0 test leaves open */
    V t(src);
    V* p = &t; p->w = 1.0f;
    return *p;
}

/* VU0 offset-is-zero test; the block deliberately does not restore .set reorder (see AsPoint) */
static inline bool IsZeroXYZ(const V* v)
{
    int k, fl;
    bool r = false;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
    }
    return r;
}

static inline void Ctor_(Obj1AF600* o, float f, V vv) {
    o->doesBoneContribute = 1;
    o->isOffsetZero = IsZeroXYZ(&vv);
    o->contributionPointRadius = f;
    o->contributionPointOffset = AsPoint(vv);
}

/* Reset: placement-construct the contribution in place (new (this) T(radius, offset)). */
extern "C" void cBone_SkeletonBBoxContribution_Reset(Obj1AF600* o, V* v, float f) {
    if (o) {
        Ctor_(o, f, *v);
    }
}
static inline void merge_flush_func_001AF600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF600 */

/* merge_units: begin func_001AF6B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSkeletonBBoxContribution_ContributionPointOffset(char* self) {
    return self + 16;
}

float cSkeletonBBoxContribution_ContributionPointRadius(char* self) {
    return *(float*)(self + 8);
}

int cSkeletonBBoxContribution_BoneIndex(char* self) {
    return *(int*)(self + 0);
}

int cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cSkeletonBBoxContributionPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cSkeletonBBoxContributionPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001AF6B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF6B0 */

/* merge_units: begin func_001AF720 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_1AF720;
typedef struct { unsigned char enable; unsigned char mode; char p2[2]; float radius; char p8[8]; V4_1AF720 centre; } S_1AF720;
extern signed char D_004E1D88;
extern float D_004E1D90;
extern float D_004E1D94;
extern float D_004E1D98;
extern float D_004E1D9C;
void cBone_SkeletonBBoxContribution_Clear(S_1AF720* s) {
    if (s != 0) {
        float z;
        V4_1AF720* d; V4_1AF720* p;
        s->enable = 0;
        s->mode = 1;
        *(int*)&s->radius = 0;
        z = 0.0f;
        if (!D_004E1D88) {
            D_004E1D88 = 1;
            D_004E1D90 = z;
            D_004E1D94 = z;
            D_004E1D98 = z;
            D_004E1D9C = z;
        }
        p = (V4_1AF720*)&D_004E1D90; d = &s->centre;
        VCopyF(d, p);
    }
}
static inline void merge_flush_func_001AF720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF720 */

/* merge_units: begin func_001AF790 */
#pragma push /* merge_units */
void* cBone_GetSkeletonBBoxContribution(char* self) {
    return self + 336;
}
static inline void merge_flush_func_001AF790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF790 */

/* merge_units: begin func_001AF7A0 */
#pragma push /* merge_units */
typedef struct { int w; } G_1AF7A0;
extern void* D_004EE9D0;
extern void* D_004EE9D8;
extern char D_0049D8D0[];
extern void cTimerDisable_ctor(G_1AF7A0* g);
extern void cTimerDisable_dtor(G_1AF7A0* g, int f);
extern void cArray_cSkeletonCenterOfMassContributionPtr_dtor(void* p, int f);
extern void cArray_cSkeletonBBoxContributionPtr_dtor(void* p, int f);
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern void cHumanIkRoutine_UnInitStatics(void);
extern void cHumanCollisionRoutine_UnInitStatics(void);
extern void cCollisionSystem_cBox_UnInitStatics(void);
extern void nCollision_UnInitStatics(void);
void cHuman_UnInitStatics(void)
{
    G_1AF7A0 g1;
    G_1AF7A0 g2;
    void* p = D_004EE9D0;
    if (p) {
        cTimerDisable_ctor(&g1);
        cArray_cSkeletonCenterOfMassContributionPtr_dtor(p, -1);
        cMemMan_Deallocate(0, p, D_0049D8D0, 0xB2A);
        cTimerDisable_dtor(&g1, -1);
        D_004EE9D0 = 0;
    }
    p = D_004EE9D8;
    if (p) {
        cTimerDisable_ctor(&g2);
        cArray_cSkeletonBBoxContributionPtr_dtor(p, -1);
        cMemMan_Deallocate(0, p, D_0049D8D0, 0xB30);
        cTimerDisable_dtor(&g2, -1);
        D_004EE9D8 = 0;
    }
    cHumanIkRoutine_UnInitStatics();
    cHumanCollisionRoutine_UnInitStatics();
    cCollisionSystem_cBox_UnInitStatics();
    nCollision_UnInitStatics();
}
static inline void merge_flush_func_001AF7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF7A0 */
