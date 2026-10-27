/*
 * SFOGame/Source/human: 4 files, 001AEFE0-001AF190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AEFE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "anim_channel_dtor.h"

/* Anim channel destructor, optionally delete. */
DEFINE_ANIM_CHANNEL_DTOR(cSplinedMotion_Scalar0To1_dtor)
static inline void merge_flush_func_001AEFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AEFE0 */

/* merge_units: begin func_001AF040 */
#pragma push /* merge_units */
#include "human_types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct AnimSlot {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Resets the slot start/current/target to v and re-evaluates its value; returns the slot. */
extern "C" AnimSlot* cSkaSliderValue_opAssign(AnimSlot* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AF040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AF040 */

/* merge_units: begin func_001AF080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(void* binding, CurveSegment* segment);
extern int cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(CurveSegment*, int, int, float);
static const float dat_0048A198[2] = { 0.0f, 0.0f };
static const float dat_0048A1A0[2] = { 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */
extern void std_tree_pair_cString_value_compare_find_cStringR_2(int*, int, int);

/* AnimChannel constructor: zero scalars, constant segment, wrapping off. */
AnimChannel* cSplinedMotion_Scalar0To1_ctor(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = (*(float*)dat_0048A198);
    self->base.current = (*(float*)dat_0048A198);
    self->base.target = (*(float*)dat_0048A1A0);
    self->base.rate = (*(float*)dat_0048A198);
    self->base.damping = 0.0f;
    cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(&self->base.segment, (int)&(*(float*)dat_0048A198), (int)&(*(float*)dat_0048A1A0), 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}

int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(int* self) {
    return *self + 24;
}

int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocArray_cString_cSkaAnimationSetPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString_cSkaAnimationSetPtr_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString_value_compare_find_cStringR_2(it, a1, a2);
    *out = it[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AF080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AF080 */

/* merge_units: begin func_001AF190 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(char *, char *);                        
int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(char *);                               
int cBone_SkeletonCenterOfMassContribution_Reset(int, float);                          
float cSkeletonCenterOfMassContribution_Weight(int);                             
int cArray_cBone_opIndex_int_2(char * , int);                     
int cSkeletonCenterOfMassContribution_BoneIndex(int);                             
int *cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(char *);                            
int cArray_cSkeletonCenterOfMassContributionPtr_End(char *, int);                          
int cArray_cSkeletonCenterOfMassContributionPtr_Begin(char *, int);                          
int cArray_cBone_Iterator_opNe(char *, char *);                        
int cArray_cBone_Iterator_opInc(char *);                               
int cBone_SkeletonCenterOfMassContribution_Clear(int);                               
int cBone_GetSkeletonCenterOfMassContribution(int);                             
int cArray_cBone_Iterator_opArrow(char *);                             
int cArray_cBone_End(char *, char * );                       
int cArray_cBone_Begin(char *, char * );                       
extern int D_004EE9D0;

void cHuman_SetupCenterOfMassInfo(char * arg0) {
    char * temp_s1;
    int sp3C;
    int temp_s0;
    int sp38;
    int sp34;
    int sp30;
    int temp_s0_2;

    temp_s0 = D_004EE9D0;
    temp_s1 = arg0 + 0x2E50;
    if (F_(arg0, 0x2E64, unsigned char) != 0) {
        cArray_cBone_Begin(&sp3C, temp_s1 + 0x18);
        cArray_cBone_End(&sp38, temp_s1 + 0x18);
        if (cArray_cBone_Iterator_opNe(&sp3C, &sp38) != 0) {
            do {
                cBone_SkeletonCenterOfMassContribution_Clear(cBone_GetSkeletonCenterOfMassContribution(cArray_cBone_Iterator_opArrow(&sp3C)));
                cArray_cBone_Iterator_opInc(&sp3C);
            } while (cArray_cBone_Iterator_opNe(&sp3C, &sp38) != 0);
        }
        cArray_cSkeletonCenterOfMassContributionPtr_Begin(&sp34, temp_s0);
        cArray_cSkeletonCenterOfMassContributionPtr_End(&sp30, temp_s0);
        if (cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(&sp34, &sp30) != 0) {
            do {
                temp_s0_2 = cBone_GetSkeletonCenterOfMassContribution(cArray_cBone_opIndex_int_2(temp_s1 + 0x18, cSkeletonCenterOfMassContribution_BoneIndex(*cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(&sp34))));
                { float ff = cSkeletonCenterOfMassContribution_Weight(*cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(&sp34)); cBone_SkeletonCenterOfMassContribution_Reset(temp_s0_2, ff); }
                cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(&sp34);
            } while (cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(&sp34, &sp30) != 0);
        }
    }
}
static inline void merge_flush_func_001AF190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF190 */
