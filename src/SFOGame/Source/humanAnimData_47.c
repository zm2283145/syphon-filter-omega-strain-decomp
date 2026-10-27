/*
 * SFOGame/Source/humanAnimData: 5 files, 001F4350-001F43F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F4350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_list_imp_voidPtr_size(void);
extern int std_vector_imp_cSkaBlendSequenceItem_reserve(int, int);

int std_vector_cSkaBlendSequenceItem_reserve(int a0, int a1) {
    return std_vector_imp_cSkaBlendSequenceItem_reserve(a0, a1);
}

int cLList_cSkaBlendSequenceItemPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}
static inline void merge_flush_func_001F4350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4350 */

/* merge_units: begin func_001F4370 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

#if 0 /* merge_units */
extern void cLList_cSkaBlendSequenceItemPtr_PushBackActual(void* obj, int* value);
#endif /* merge_units */
void cLList_cSkaBlendSequenceItemPtr_PushBackActual(); /* merge_units */


/* Passes value by reference to cLList_cSkaBlendSequenceItemPtr_PushBackActual; returns obj. */
void* cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(void* obj, int value) {
    cLList_cSkaBlendSequenceItemPtr_PushBackActual(obj, &value);
    return obj;
}

#pragma pop
static inline void merge_flush_func_001F4370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4370 */

/* merge_units: begin func_001F43B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_push_back(void* s);
#endif /* merge_units */
void std_list_cSkaBlendSequenceItemPtr_push_back(); /* merge_units */

#pragma optimization_level 1
void cLList_cSkaBlendSequenceItemPtr_PushBackActual(void* s) { std_list_cSkaBlendSequenceItemPtr_push_back(s); }
#pragma optimization_level reset
static inline void merge_flush_func_001F43B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F43B0 */

/* merge_units: begin func_001F43D0 */
#pragma push /* merge_units */
#pragma optimization_level 1

extern void std_list_imp_voidPtr_push_back(void);

/* Forwards to std_list_imp_voidPtr_push_back. */
void std_list_cSkaBlendSequenceItemPtr_push_back(void) {
    std_list_imp_voidPtr_push_back();
}
static inline void merge_flush_func_001F43D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F43D0 */

/* merge_units: begin func_001F43F0 */
#pragma push /* merge_units */
extern void* cSkaAnimationSet_GetNode_cString16NR(int id);
extern void cPointer_cSkaNode_ctor_cSkaNodeP(void* self, void* motion);
extern void cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(void* dst, void* src);

/* Resolves the child's motion by id and copies its thresholds. */
void* cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(char* self, int unused, int id, void* thresholds)
{
    cPointer_cSkaNode_ctor_cSkaNodeP(self, cSkaAnimationSet_GetNode_cString16NR(id));
    cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(self + 4, thresholds);
    return self;
}
static inline void merge_flush_func_001F43F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F43F0 */
