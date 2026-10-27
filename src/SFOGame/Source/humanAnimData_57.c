/*
 * SFOGame/Source/humanAnimData: 3 files, 00201C10-00201D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201C10 */
#pragma push /* merge_units */
#include "types.h"
extern int* std_vector_deleter_cSkaBlendSequenceItem_data_void_2(void);
/* Return the value pointed to by std_vector_deleter_cSkaBlendSequenceItem_data_void_2(). */
int std_vector_imp_cSkaBlendSequenceItem_begin_void(void)
{
    return *std_vector_deleter_cSkaBlendSequenceItem_data_void_2();
}
static inline void merge_flush_func_00201C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201C10 */

/* merge_units: begin func_00201C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern void* D_004DFBF0;
extern MotionNode* cSkaNode_ctor_cSkaNodeR_cQuaternionR(MotionNode*, MotionNode*);
extern ObjVec* cArray_cSkaBlendSequenceItem_ctor_cArrayR(ObjVec*, ObjVec*);
extern int cQuaternion_opAssign(int*, int*);
#if 0 /* merge_units */
extern int std_vector_cSkaBlendSequenceItem_ctor_vectorR(ObjVec*);
#endif /* merge_units */
int std_vector_cSkaBlendSequenceItem_ctor_vectorR(); /* merge_units */


/* Copy of the MotionNode base part (type byte and name). */
MotionNode* cSkaNode_opAssign(MotionNode* dst, MotionNode* src) {
    dst->type = src->type;
    cQuaternion_opAssign(&dst->name, &src->name);
    return dst;
}

/* MotionSlider copy constructor. */
MotionSlider* cSkaSlider_ctor_cSkaSliderR_cQuaternionR(MotionSlider* dst, MotionSlider* src) {
    cSkaNode_ctor_cSkaNodeR_cQuaternionR(&dst->base, &src->base);
    dst->base.vtable = &D_004DFBF0;
    dst->unk20 = src->unk20;
    cArray_cSkaBlendSequenceItem_ctor_cArrayR(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* cArray_cSkaBlendSequenceItem_ctor_cArrayR(ObjVec* dst, ObjVec* src) {
    std_vector_cSkaBlendSequenceItem_ctor_vectorR(dst);
    dst->owned = src->owned;
    return dst;
}
static inline void merge_flush_func_00201C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201C30 */

/* merge_units: begin func_00201D20 */
#pragma push /* merge_units */
extern int std_vector_imp_cSkaBlendSequenceItem_ctor_vectorimpR(int, int);

int std_vector_cSkaBlendSequenceItem_ctor_vectorR(int a0, int a1) {
    std_vector_imp_cSkaBlendSequenceItem_ctor_vectorimpR(a0, a1);
    return a0;
}
static inline void merge_flush_func_00201D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201D20 */
