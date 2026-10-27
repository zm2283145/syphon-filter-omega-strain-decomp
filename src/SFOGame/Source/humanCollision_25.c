/*
 * SFOGame/Source/humanCollision: 6 files, 001EB0F0-001EB340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB0F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign: HumanColPreset entry assignment (implicit member-wise operator=: bitset masks, float groups, flags, quad vectors) */
struct Bits {
    int w[1];
    Bits() {}
    Bits& operator=(const Bits& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
};
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct F4 { float a, b, c, d; };
struct F3 { float a, b, c; };
/* one-byte struct member: MW copies it through address registers like retail */
struct B1 { unsigned char v; };
struct Shape { V a; V b; V c; B1 flag; float r; V d; V e; };
struct Col {
    signed char b0;
    Bits m4, m8, mC, m10;
    F4 f14;
    F3 f24;
    unsigned char x30, x31, x32;
    Shape shape;
    Bits mA0;
    V qB0, qC0, qD0;
    float xE0, xE4;
};
extern "C" Col* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign(Col* d, const Col* s)
{
    *d = *s;
    return d;
}
static inline void merge_flush_func_001EB0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB0F0 */

/* merge_units: begin func_001EB2C0 */
#pragma push /* merge_units */
int cBitArray_19_ctor_bool(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001EB2D8;
    *(int*)(char*)a0 = v0;
    goto L001EB2E0;
L001EB2D8:;
    *(int*)(char*)a0 = 0;
L001EB2E0:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_001EB2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB2C0 */

/* merge_units: begin humanCollision_1EB2F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

/* Reset the state block that follows a mask set (+0x30 flag, +0x50/+0x54 ids). */
Unk001EB2F0* cCollisionEdge_ctor(Unk001EB2F0* self) {
    self->unk30 = 0;
    self->unk50 = -1;
    self->unk54 = -1;
    self->unk58 = 0;
    return self;
}

/* Fill four mask words from pointers (same layout as HumanColPreset +0x04..+0x10). */
IntQuad* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_ctor(IntQuad* self, int* m0, int* m1, int* m2, int* m3) {
    self->v[0] = *m0;
    self->v[1] = *m1;
    self->v[2] = *m2;
    self->v[3] = *m3;
    return self;
}
static inline void merge_flush_humanCollision_1EB2F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end humanCollision_1EB2F0 */

/* merge_units: begin func_001EB340 */
#pragma push /* merge_units */
#include "humanCollision_types.h"

/* Copy-assign of a preset configuration. */
HumanColPresetCfg* cHumanCollisionRoutine_cLedgeSearchLimits_ctor(HumanColPresetCfg* dst, HumanColPresetCfg* src) {
    dst->range0Min = src->range0Min;
    dst->range0Max = src->range0Max;
    dst->range1Min = src->range1Min;
    dst->range1Max = src->range1Max;
    dst->range2Min = src->range2Min;
    dst->range2Max = src->range2Max;
    dst->enabled = src->enabled;
    return dst;
}

Word* cBitArray_5_ctor_cBitArrayR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* cBitArray_19_ctor_cBitArrayR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_001EB340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB340 */

/* merge_units: begin func_001EB3A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(int, int, char *, int);
int __destroy_array(int, char *, int, int);
int std_vector_deleter_cEdgeGroup_dtor(int, int); /* buffer A dtor */
int std_vector_deleter_cCollisionEdge_dtor(int, int); /* buffer B dtor */
extern int g_HumanColPresetMgr; /* HumanColPresetMgr* */
extern int g_HumanColBufB; /* HumanColVec* (buffer B) */
extern int g_HumanColBufA; /* HumanColVec* (buffer A) */
extern unsigned char g_ProfileLockEnabled;
extern char cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor;
}
/* Destroy and free the preset manager and both buffers. */
extern "C" void cHumanCollisionRoutine_UnInitStatics(void) {
    int mgr;
    int bufB;
    int bufA;

    mgr = g_HumanColPresetMgr;
    if (mgr != 0) {
        {
            AllocGuard g;
        if ((mgr != 0) && (mgr != 0)) {
            __destroy_array(mgr + 0x10, &cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor, sizeof(HumanColPreset), HUMANCOL_PRESET_COUNT);
        }
        cMemMan_Deallocate(0, mgr, "humanCollision.cc", 0x3F6);
        }
        g_HumanColPresetMgr = 0;
    }
    bufB = g_HumanColBufB;
    if (bufB != 0) {
        {
            AllocGuard g;
        if ((bufB != 0) && (bufB != 0) && (bufB != 0)) {
            std_vector_deleter_cCollisionEdge_dtor(bufB, 0);
        }
        cMemMan_Deallocate(0, bufB, "humanCollision.cc", 0x3FE);
        }
        g_HumanColBufB = 0;
    }
    bufA = g_HumanColBufA;
    if (bufA != 0) {
        {
            AllocGuard g;
        if ((bufA != 0) && (bufA != 0) && (bufA != 0) && (bufA != 0)) {
            std_vector_deleter_cEdgeGroup_dtor(bufA, 0);
        }
        cMemMan_Deallocate(0, bufA, "humanCollision.cc", 0x406);
        }
        g_HumanColBufA = 0;
    }
}
static inline void merge_flush_func_001EB3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB3A0 */

/* merge_units: begin func_001EB5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
int cHumanCollisionRoutine_InitLedgeSearchWorkSpace(...);                        
int *cMemMan_Allocate(...);                       
int __construct_array(...);            
int cArrayCapacity_Int(...);                     /* returns *p */
int cArray_cEdgeGroup_ctor(...);
int std_vector_cCollisionEdge_reserve(...);
int std_vector_cCollisionEdge_ctor(...);
extern char D_004A04A0;                     /* "humanCollision.cc" */
#if 0 /* merge_units */
extern int *g_HumanColPresetMgr;
#endif /* merge_units */
#define g_HumanColPresetMgr (*(int **)&g_HumanColPresetMgr) /* merge_units */


#if 0 /* merge_units */
extern int *g_HumanColBufB;
#endif /* merge_units */
#define g_HumanColBufB (*(int **)&g_HumanColBufB) /* merge_units */


#if 0 /* merge_units */
extern int *g_HumanColBufA;
#endif /* merge_units */
#define g_HumanColBufA (*(int **)&g_HumanColBufA) /* merge_units */


extern char cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_void;
}
/* Allocate the preset manager (then install the presets) and both buffers. */
extern "C" void cHumanCollisionRoutine_InitStatics(void) {
    int capB;
    int capA;
    int *mgr;
    int *bufB;
    int *bufA;

    if (g_HumanColPresetMgr == NULL) {
        {
            AllocGuard g;
        mgr = cMemMan_Allocate(0, sizeof(HumanColPresetMgr), &D_004A04A0, 0x3DC);
        }
        if (mgr != NULL) {
            ((HumanColPresetMgr *)mgr)->count = 0;
            __construct_array((char *)mgr + 0x10, &cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_void, &cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor, sizeof(HumanColPreset), HUMANCOL_PRESET_COUNT);
        }
        g_HumanColPresetMgr = mgr;
        cHumanCollisionRoutine_InitLedgeSearchWorkSpace();
    }
    if (g_HumanColBufB == NULL) {
        {
            AllocGuard g;
        bufB = cMemMan_Allocate(0, sizeof(HumanColVec), &D_004A04A0, 0x3E4);
        }
        if (bufB != NULL) {
            capB = HUMANCOL_VEC_RESERVE;
            std_vector_cCollisionEdge_ctor(bufB);
            std_vector_cCollisionEdge_reserve(bufB, cArrayCapacity_Int(&capB));
            ((HumanColVec *)bufB)->flag0C = 1;
        }
        g_HumanColBufB = bufB;
    }
    if (g_HumanColBufA == NULL) {
        {
            AllocGuard g;
        bufA = cMemMan_Allocate(0, sizeof(HumanColVec), &D_004A04A0, 0x3EB);
        }
        if (bufA != NULL) {
            capA = HUMANCOL_VEC_RESERVE;
            cArray_cEdgeGroup_ctor(bufA, &capA, 1);
        }
        g_HumanColBufA = bufA;
    }
}
#undef g_HumanColPresetMgr /* merge_units */
#undef g_HumanColBufB /* merge_units */
#undef g_HumanColBufA /* merge_units */
static inline void merge_flush_func_001EB5C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB5C0 */
