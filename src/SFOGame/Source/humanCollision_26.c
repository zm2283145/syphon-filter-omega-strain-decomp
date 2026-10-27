/*
 * SFOGame/Source/humanCollision: 3 files, 001EB800-001EB850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB800 */
#pragma push /* merge_units */
#include "types.h"
#include "humanCollision_types.h"

#if 0 /* merge_units */
extern void std_vector_imp_cEdgeGroup_ctor(HumanColVec* v);
#endif /* merge_units */
HumanColVec * std_vector_imp_cEdgeGroup_ctor(); /* merge_units */

extern void std_vector_imp_cEdgeGroup_reserve(HumanColVec* v, int capacity); /* vector reserve (buffer A) */

/* Constructor for buffer A: empty vector, reserve *capacity, store the flag byte; returns v. */
HumanColVec* cArray_cEdgeGroup_ctor(HumanColVec* v, int* capacity, char flag)
{
    std_vector_imp_cEdgeGroup_ctor(v);
    std_vector_imp_cEdgeGroup_reserve(v, *capacity);
    v->flag0C = flag;
    return v;
}
static inline void merge_flush_func_001EB800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB800 */

/* merge_units: begin func_001EB850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_imp_cCollisionEdge_reserve(int, int);  /* vector reserve (buffer B) */

/* Empty vector (buffer A). */
HumanColVec* std_vector_imp_cEdgeGroup_ctor(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int std_vector_cCollisionEdge_reserve(int v, int n) {
    return std_vector_imp_cCollisionEdge_reserve(v, n);
}

/* Empty vector (buffer B). */
HumanColVec* std_vector_cCollisionEdge_ctor(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}
static inline void merge_flush_func_001EB850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB850 */

/* merge_units: begin func_001EB8A0 */
#pragma push /* merge_units */
#define FLT_MAX 3.4028235e38f
extern void cBitArray_19_ctor_bool(HumanColMask* m, int all);
extern void cBitArray_5_ctor_bool(HumanColMask* m, int all);
/* Constructor: clears the masks and sets unbounded ranges. */
HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_void(HumanColPreset* p)
{
    HumanColMask* masks;
    p->selector = -1;
    masks = p->masks;
    cBitArray_19_ctor_bool(&masks[0], 0);
    cBitArray_19_ctor_bool(&masks[1], 0);
    cBitArray_5_ctor_bool(&masks[2], 0);
    cBitArray_5_ctor_bool(&masks[3], 0);
    p->cfg.range0Min = -FLT_MAX;
    p->cfg.range0Max = FLT_MAX;
    p->cfg.range1Min = -FLT_MAX;
    p->cfg.range1Max = FLT_MAX;
    p->cfg.range2Min = -FLT_MAX;
    p->cfg.range2Max = FLT_MAX;
    p->cfg.enabled = 0;
    p->descFlag = 0;
    p->active = 0;
    p->unk32 = 0;
    p->unk70 = 0;
    p->unk90 = -1;
    p->unk94 = -1;
    p->unk98 = 0;
    p->unkA0 = 0;
    p->bestHeight = -FLT_MAX;
    p->unkE4 = 0;
    return p;
}
static inline void merge_flush_func_001EB8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB8A0 */
