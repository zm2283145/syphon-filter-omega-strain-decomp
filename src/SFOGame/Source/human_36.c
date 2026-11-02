/*
 * SFOGame/Source/human: 6 files, 001AFCF0-001B06D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AFCF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(void*, int);

int std_vector_cSkeletonBBoxContributionPtr_reserve(void* self, int arg) {
    return std_vector_pod_int_reserve(self, arg);
}

Rel* std_vector_cSkeletonBBoxContributionPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_cSkeletonCenterOfMassContributionPtr_reserve(void* self, int arg) {
    return std_vector_pod_int_reserve(self, arg);
}

Rel* std_vector_cSkeletonCenterOfMassContributionPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001AFCF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AFCF0 */

/* merge_units: begin func_001AFD50 */
#pragma push /* merge_units */
/* InitStatics_BBox: build the static table of bone-attached bounding spheres once
   (each element registered for destruction) and push a pointer to every entry into out. */
#pragma inline_depth(10)
#pragma cplusplus on

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

/* Bone-attached bounding sphere: bone index, offset-is-zero flag, radius, offset point. */
struct Sphere {
    int bone;
    unsigned char zero;
    float radius;
    V offset;
};

struct PtrVec;

extern "C" {
V* cVector_ctor_cVectorR(V* d, const V* s);
V* cVector_SetW(V* v, float w);
#if 0 /* merge_units */
void cSkeletonBBoxContribution_dtor(Sphere* s, int flags);
#endif /* merge_units */
void* cSkeletonBBoxContribution_dtor(void* self, short deleteFlag); /* merge_units */
#define cSkeletonBBoxContribution_dtor(a0, a1) ((void)cSkeletonBBoxContribution_dtor((void *)(a0), (short)(a1))) /* merge_units */

int __register_global_object(void* obj, void* dtor, void* rec);
#if 0 /* merge_units */
int std_vector_cSkeletonBBoxContributionPtr_push_back(PtrVec* v, Sphere** p);
#endif /* merge_units */
int std_vector_cSkeletonBBoxContributionPtr_push_back(PtrVec* v, int value); /* merge_units */
#define std_vector_cSkeletonBBoxContributionPtr_push_back(a0, a1) (std_vector_cSkeletonBBoxContributionPtr_push_back((a0), (int)(a1))) /* merge_units */


extern signed char D_004EEAE0;
extern char D_004EEAE8[12][0x10];
extern Sphere D_004EEBB0[12];
}

static inline V AsPoint(const V& v)
{
    V t;
    V* r = cVector_SetW(cVector_ctor_cVectorR(&t, &v), 1.0f);
    asm { .set reorder } /* scheduling: ends the noreorder region the VU0 test leaves open (retail order up to here) */
    return *r;
}

/* VU0 offset-is-zero test; the block deliberately does not restore .set reorder (see AsPoint) */
static inline unsigned char IsZeroXYZ(const V* v)
{
    int k, fl;
    unsigned char r;
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

static inline void InitSphere(Sphere* s, int bone, const V& off, float radius)
{
    s->bone = bone;
    s->zero = IsZeroXYZ(&off);
    s->radius = radius;
    s->offset = AsPoint(off);
}

extern "C" void InitStatics_BBox(PtrVec* out)
{
    int i;
    if (!D_004EEAE0) {
        InitSphere(&D_004EEBB0[0], 0x0, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[0], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[0]);
        InitSphere(&D_004EEBB0[1], 0x4, V(0.0f, 0.0f, 0.0f, 0.0f), 0.41666666f);
        __register_global_object(&D_004EEBB0[1], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[1]);
        InitSphere(&D_004EEBB0[2], 0x6, V(0.0f, 0.0f, 0.0f, 0.0f), 0.41666666f);
        __register_global_object(&D_004EEBB0[2], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[2]);
        InitSphere(&D_004EEBB0[3], 0xc, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[3], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[3]);
        InitSphere(&D_004EEBB0[4], 0x10, V(0.0f, 0.0f, 0.0f, 0.0f), 0.75f);
        __register_global_object(&D_004EEBB0[4], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[4]);
        InitSphere(&D_004EEBB0[5], 0xe, V(0.0f, 0.0f, 0.0f, 0.0f), 1.0f);
        __register_global_object(&D_004EEBB0[5], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[5]);
        InitSphere(&D_004EEBB0[6], 0xd, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[6], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[6]);
        InitSphere(&D_004EEBB0[7], 0xf, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[7], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[7]);
        InitSphere(&D_004EEBB0[8], 0x11, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[8], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[8]);
        InitSphere(&D_004EEBB0[9], 0x12, V(0.0f, 0.0f, 0.0f, 0.0f), 0.33333334f);
        __register_global_object(&D_004EEBB0[9], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[9]);
        InitSphere(&D_004EEBB0[10], 0x13, V(0.0f, 0.0f, 0.0f, 0.0f), 0.6666667f);
        __register_global_object(&D_004EEBB0[10], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[10]);
        InitSphere(&D_004EEBB0[11], 0x14, V(0.0f, 0.0f, 0.0f, 0.0f), 0.6666667f);
        __register_global_object(&D_004EEBB0[11], (void*)cSkeletonBBoxContribution_dtor, D_004EEAE8[11]);
        D_004EEAE0 = 1;
    }
    for (i = 0; i < 12; i++) {
        Sphere* p;
        Sphere** pp = &p;
        p = &D_004EEBB0[i];
        std_vector_cSkeletonBBoxContributionPtr_push_back(out, pp);
    }
}
#undef cSkeletonBBoxContribution_dtor /* merge_units */
#undef std_vector_cSkeletonBBoxContributionPtr_push_back /* merge_units */
static inline void merge_flush_func_001AFD50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AFD50 */

/* merge_units: begin func_001B06D0 */
#pragma push /* merge_units */
#include "human_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int);

/* push_back: insert one value at end(). */
int std_vector_cSkeletonBBoxContributionPtr_push_back(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001B06D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B06D0 */

/* merge_units: begin func_001B06F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkeletonBBoxContribution_dtor)
static inline void merge_flush_func_001B06F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B06F0 */

/* merge_units: begin func_001B0740 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int __register_global_object(int *, char *, char *);
#endif /* merge_units */
#define __register_global_object(a0, a1, a2) (__register_global_object((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */
        
#if 0 /* merge_units */
int std_vector_cSkeletonCenterOfMassContributionPtr_push_back(int, int **);
#endif /* merge_units */
int std_vector_cSkeletonCenterOfMassContributionPtr_push_back(); /* merge_units */

                       
extern signed char D_004EE9E0;
extern char D_004EE9E8;
extern char D_004EE9F8;
extern char D_004EEA08;
extern char D_004EEA18;
extern char D_004EEA28;
extern char D_004EEA38;
extern char D_004EEA48;
extern char D_004EEA58;
extern char D_004EEA68;
extern char D_004EEA78;
extern int D_004EEA90;
extern int D_004EEA94;
extern int D_004EEA98;
extern int D_004EEA9C;
extern int D_004EEAA0;
extern int D_004EEAA4;
extern int D_004EEAA8;
extern int D_004EEAAC;
extern int D_004EEAB0;
extern int D_004EEAB4;
extern int D_004EEAB8;
extern int D_004EEABC;
extern int D_004EEAC0;
extern int D_004EEAC4;
extern int D_004EEAC8;
extern int D_004EEACC;
extern int D_004EEAD0;
extern int D_004EEAD4;
extern int D_004EEAD8;
extern int D_004EEADC;
extern char cSkeletonCenterOfMassContribution_dtor;

void InitStatics_CenterOfMass(int arg0) {
    int var_s2;
    int *sp4C;
    int *var_s1;

    if (D_004EE9E0 == 0) {
        D_004EEA90 = 2;
        D_004EEA94 = 0x3FA00000;
        __register_global_object(&D_004EEA90, &cSkeletonCenterOfMassContribution_dtor, &D_004EE9E8);
        D_004EEA98 = 5;
        D_004EEA9C = 0x3FA00000;
        __register_global_object(&D_004EEA98, &cSkeletonCenterOfMassContribution_dtor, &D_004EE9F8);
        D_004EEAA0 = 4;
        D_004EEAA4 = 0x3E800000;
        __register_global_object(&D_004EEAA0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA08);
        D_004EEAA8 = 6;
        D_004EEAAC = 0x3E800000;
        __register_global_object(&D_004EEAA8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA18);
        D_004EEAB0 = 7;
        D_004EEAB4 = 0x3D4CCCCD;
        __register_global_object(&D_004EEAB0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA28);
        D_004EEAB8 = 0xB;
        D_004EEABC = 0x3D4CCCCD;
        __register_global_object(&D_004EEAB8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA38);
        D_004EEAC0 = 0x11;
        D_004EEAC4 = 0x3E19999A;
        __register_global_object(&D_004EEAC0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA48);
        D_004EEAC8 = 0x12;
        D_004EEACC = 0x3E19999A;
        __register_global_object(&D_004EEAC8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA58);
        D_004EEAD0 = 0x13;
        D_004EEAD4 = 0x3CCCCCCD;
        __register_global_object(&D_004EEAD0, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA68);
        D_004EEAD8 = 0x14;
        D_004EEADC = 0x3CCCCCCD;
        __register_global_object(&D_004EEAD8, &cSkeletonCenterOfMassContribution_dtor, &D_004EEA78);
        D_004EE9E0 = 1;
    }
    var_s2 = 0;
    var_s1 = &D_004EEA90;
    do {
        sp4C = var_s1;
        std_vector_cSkeletonCenterOfMassContributionPtr_push_back(arg0, &sp4C);
        var_s2 += 1;
        var_s1 += 2;
    } while (var_s2 < 0xA);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B0740(void) {}
#undef __register_global_object /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B0740 */

/* merge_units: begin func_001B09E0 */
#pragma push /* merge_units */
/* push_back: insert one value at end(). */
int std_vector_cSkeletonCenterOfMassContributionPtr_push_back(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001B09E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B09E0 */
