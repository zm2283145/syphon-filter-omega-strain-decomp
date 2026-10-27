/*
 * main/humanCollision: 3 files, 001EB340-001EB5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
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
#pragma pop /* merge_units */
/* merge_units: end func_001EB5C0 */
