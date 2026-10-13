/*
 * main/humanCollision: 2 files, 001EB850-001EB8A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanCollision_types.h"

extern int func_001EF6C0(int, int);  /* vector reserve (buffer B) */

/* Empty vector (buffer A). */
HumanColVec* HumanColBufA_Init(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int HumanColBufB_Reserve(int v, int n) {
    return func_001EF6C0(v, n);
}

/* Empty vector (buffer B). */
HumanColVec* HumanColBufB_Init(HumanColVec* v) {
    v->capacity = 0;
    v->count = 0;
    v->data = 0;
    return v;
}
#pragma pop /* merge_units */
/* merge_units: end func_001EB850 */

/* merge_units: begin func_001EB8A0 */
#pragma push /* merge_units */
#define FLT_MAX 3.4028235e38f
extern void HumanColMask_Ctor(HumanColMask* m, int all);
extern void HumanColQueryMask_Ctor(HumanColMask* m, int all);
/* Constructor: clears the masks and sets unbounded ranges. */
HumanColPreset* HumanColPreset_Ctor(HumanColPreset* p)
{
    HumanColMask* masks;
    p->selector = -1;
    masks = p->masks;
    HumanColMask_Ctor(&masks[0], 0);
    HumanColMask_Ctor(&masks[1], 0);
    HumanColQueryMask_Ctor(&masks[2], 0);
    HumanColQueryMask_Ctor(&masks[3], 0);
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
#pragma pop /* merge_units */
/* merge_units: end func_001EB8A0 */
