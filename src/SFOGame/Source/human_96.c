/*
 * SFOGame/Source/human: 1 file, 001AEE90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AEE90 */
#pragma push /* merge_units */
#include "types.h"

typedef struct ModelDef {
    int unk00;
    char roots[0x50];   /* 0x04 */
    int channelCount;   /* 0x54 */
    int pairCount;      /* 0x58 */
} ModelDef;

typedef struct ModelInst {
    char pad00[0x24];
    ModelDef* def;      /* 0x24 */
    char pad28[0x50];
    char channels[0x10];/* 0x78 */
    char pairs[0x18];   /* 0x88 */
    char roots[4];      /* 0xA0 */
} ModelInst;

typedef struct AnimChannel {
    char data[0x48];
} AnimChannel;

typedef struct IntPair2 {
    int a, b;
} IntPair2;

extern void cSkaAnimAnchorList_Reset(void* roots, void* src);
extern void cSplinedMotion_Scalar0To1_ctor(AnimChannel* ch);
extern void cSkaSliderValue_opAssign(AnimChannel* ch, float t);
extern void std_vector_imp_cSkaSliderValue_resize(void* vec, int count, AnimChannel* fill);
extern void cSplinedMotion_Scalar0To1_dtor(AnimChannel* ch, int flags);
extern void std_vector_imp_cSkaSwitchValue_resize(void* vec, int count, IntPair2* fill);

/* Attaches a model definition: roots, animation channels and pair table. */
void cSkaParams_HandleNewAnimationSet(ModelInst* inst, ModelDef* def) {
    AnimChannel ch;
    IntPair2 pair;
    inst->def = def;
    cSkaAnimAnchorList_Reset(inst->roots, def->roots);
    cSplinedMotion_Scalar0To1_ctor(&ch);
    cSkaSliderValue_opAssign(&ch, 0.0f);
    std_vector_imp_cSkaSliderValue_resize(inst->channels, def->channelCount, &ch);
    cSplinedMotion_Scalar0To1_dtor(&ch, -1);
    pair.a = 0;
    pair.b = 0;
    std_vector_imp_cSkaSwitchValue_resize(inst->pairs, def->pairCount, &pair);
}
static inline void merge_flush_func_001AEE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AEE90 */
