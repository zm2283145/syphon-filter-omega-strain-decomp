/*
 * SFOGame/Source/humanAnimData: 3 files, 00201A90-00201B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00201A90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* cArray_cSkaBlendSequenceItem_opAssign(ObjVec*, ObjVec*);
#if 0 /* merge_units */
extern int std_vector_cSkaBlendSequenceItem_opAssign(ObjVec*);
#endif /* merge_units */
int std_vector_cSkaBlendSequenceItem_opAssign(); /* merge_units */


extern MotionNode* cSkaNode_opAssign(MotionNode*, MotionNode*);

/* Copy of a MotionSlider-layout node (vtable left to the caller). */
MotionSlider* cSkaSlider_opAssign(MotionSlider* dst, MotionSlider* src) {
    cSkaNode_opAssign(&dst->base, &src->base);
    dst->unk20 = src->unk20;
    cArray_cSkaBlendSequenceItem_opAssign(&dst->children, &src->children);
    dst->unk34 = src->unk34;
    dst->unk35 = src->unk35;
    return dst;
}

ObjVec* cArray_cSkaBlendSequenceItem_opAssign(ObjVec* dst, ObjVec* src) {
    std_vector_cSkaBlendSequenceItem_opAssign(dst);
    dst->owned = src->owned;
    return dst;
}
static inline void merge_flush_func_00201A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201A90 */

/* merge_units: begin func_00201B30 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int std_vector_imp_cSkaBlendSequenceItem_opAssign(int, int);
#endif /* merge_units */
void * std_vector_imp_cSkaBlendSequenceItem_opAssign(); /* merge_units */


int std_vector_cSkaBlendSequenceItem_opAssign(int a0, int a1) {
    std_vector_imp_cSkaBlendSequenceItem_opAssign(a0, a1);
    return a0;
}
static inline void merge_flush_func_00201B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201B30 */

/* merge_units: begin func_00201B60 */
#pragma push /* merge_units */
typedef struct { char c; } Tag_201B60;
extern int std_vector_imp_cSkaBlendSequenceItem_begin_void(void* o);
extern int std_vector_imp_cSkaBlendSequenceItem_end_void_2(void* o);
extern void std_vector_imp_cSkaBlendSequenceItem_do_assign(void* self, int first, int last, Tag_201B60 t);
void* std_vector_imp_cSkaBlendSequenceItem_opAssign(void* self, void* o)
{
    if (self != o) {
        Tag_201B60 t;
        int first = std_vector_imp_cSkaBlendSequenceItem_begin_void(o);
        std_vector_imp_cSkaBlendSequenceItem_do_assign(self, first, std_vector_imp_cSkaBlendSequenceItem_end_void_2(o), t);
    }
    return self;
}
static inline void merge_flush_func_00201B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00201B60 */
