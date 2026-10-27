/*
 * SFOGame/Source/human: 5 files, 001AF2C0-001AF400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AF2C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_001AF2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF2C0 */

/* merge_units: begin func_001AF300 */
#pragma push /* merge_units */
void cBone_SkeletonCenterOfMassContribution_Reset(int a0, float f12) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF310;
    *(float*)(char*)a0 = f12;
L001AF310:;
    goto ret;
ret:;
}
static inline void merge_flush_func_001AF300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF300 */

/* merge_units: begin func_001AF320 */
#pragma push /* merge_units */
float cSkeletonCenterOfMassContribution_Weight(char* self) {
    return *(float*)(self + 4);
}

/* Address of 464-byte skeleton node i. */
char* cArray_cBone_opIndex_int_2(PtrVec* v, int i) {
    char* data = (char*)v->data;

    return data + i * 464;
}

int cSkeletonCenterOfMassContribution_BoneIndex(char* self) {
    return *(int*)(self + 0);
}

int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cSkeletonCenterOfMassContributionPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cSkeletonCenterOfMassContributionPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int cArray_cBone_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 464-byte nodes. */
Iter16* cArray_cBone_Iterator_opInc(Iter16* it) {
    it->p = it->p + 464;
    return it;
}
static inline void merge_flush_func_001AF320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF320 */

/* merge_units: begin func_001AF3E0 */
#pragma push /* merge_units */
void cBone_SkeletonCenterOfMassContribution_Clear(int a0) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF3F0;
    *(int*)(char*)a0 = 0;
L001AF3F0:;
    goto ret;
ret:;
}
static inline void merge_flush_func_001AF3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF3E0 */

/* merge_units: begin func_001AF400 */
#pragma push /* merge_units */
void* cBone_GetSkeletonCenterOfMassContribution(char* self) {
    return self + 368;
}

int cArray_cBone_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 464-byte nodes. */
void cArray_cBone_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 464;
}

void cArray_cBone_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001AF400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AF400 */
