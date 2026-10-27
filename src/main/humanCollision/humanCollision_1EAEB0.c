/*
 * main/humanCollision: 3 files, 001EAEB0-001EAF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EAEB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cBitArray_19_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_001EAEB0 */

/* merge_units: begin func_001EAEC0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct F1 { unsigned char v; } F1;
typedef struct EA { V4 a; V4 b; V4 c; F1 f; float g; V4 d; V4 e; } EA;
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
EA* cCollisionEdge_opAssign(EA* d, const EA* s)
{
    V4_Copy(&d->a, &s->a);
    V4_Copy(&d->b, &s->b);
    V4_Copy(&d->c, &s->c);
    d->f = s->f;
    d->g = s->g;
    V4_Copy(&d->d, &s->d);
    V4_Copy(&d->e, &s->e);
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_001EAEC0 */

/* merge_units: begin func_001EAF30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Just below the humanCollision.cc range; these are humanCollision preset helpers
 * (see research HUMAN_COLLISION.md).
 */

#include "loose00_types.h"

/* 16-byte copy. */
Quad* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_opAssign(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Configure a collision preset: selector, four candidate masks, the
 * height/distance/cosine ranges and flags; resets per-frame state. */
HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc(HumanColPreset* p, int selector, int* mask0, int* mask1,
                                         int* mask2, int* mask3, HumanColPresetCfg* cfg, int enabled) {
    p->selector = selector;
    p->masks[0].bits = *mask0;
    p->masks[1].bits = *mask1;
    p->masks[2].bits = *mask2;
    p->masks[3].bits = *mask3;
    p->cfg.range0Min = cfg->range0Min;
    p->cfg.range0Max = cfg->range0Max;
    p->cfg.range1Min = cfg->range1Min;
    p->cfg.range1Max = cfg->range1Max;
    p->cfg.range2Min = cfg->range2Min;
    p->cfg.range2Max = cfg->range2Max;
    p->cfg.enabled = cfg->enabled;
    p->descFlag = enabled;
    p->active = 0;
    p->unk32 = 0;
    p->unk70 = 0;
    p->unk90 = -1;
    p->unk94 = -1;
    p->unk98 = 0;
    p->unkA0 = 0;
    p->bestHeight = -3.4028234663852886e38f; /* -FLT_MAX */
    p->unkE4 = 0;
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_001EAF30 */
