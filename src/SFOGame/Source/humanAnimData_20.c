/*
 * SFOGame/Source/humanAnimData: 12 files, 001F41F0-001F44B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F41F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_end_void_2(Word*, int);
extern Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word*, Word*);
extern Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);

Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listR(Word* dst, Word* src) {
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, src);
    return dst;
}

void std_list_cSkaBlendSequenceItemPtr_end(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_end_void_2(&tmp, a1);
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

Word* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, &tmp);
    return dst;
}
static inline void merge_flush_func_001F41F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F41F0 */

/* merge_units: begin func_001F4290 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_begin(int* out);
#endif /* merge_units */
void std_list_cSkaBlendSequenceItemPtr_begin(); /* merge_units */


extern void cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(void* obj, int* value);
/* Fetch a value with std_list_cSkaBlendSequenceItemPtr_begin and pass it to cConstLListIterator_cSkaBlendSequenceItemPtr_ctor. */
void cLList_cSkaBlendSequenceItemPtr_Begin(void* obj)
{
    int value;
    std_list_cSkaBlendSequenceItemPtr_begin(&value);
    cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(obj, &value);
}
static inline void merge_flush_func_001F4290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4290 */

/* merge_units: begin func_001F42D0 */
#pragma push /* merge_units */
extern void std_list_deleter_voidPtr_begin_void_2(Word*, int);
extern void std_vector_cSkaBlendSequenceItem_clear(void);
#if 0 /* merge_units */
extern void std_vector_imp_cSkaBlendSequenceItem_clear(void);
#endif /* merge_units */
void std_vector_imp_cSkaBlendSequenceItem_clear(); /* merge_units */



void std_list_cSkaBlendSequenceItemPtr_begin(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_begin_void_2(&tmp, a1);
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

void cArray_cSkaBlendSequenceItem_Clear(void) {
    std_vector_cSkaBlendSequenceItem_clear();
}

void std_vector_cSkaBlendSequenceItem_clear(void) {
    std_vector_imp_cSkaBlendSequenceItem_clear();
}
static inline void merge_flush_func_001F42D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F42D0 */

/* merge_units: begin func_001F4330 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_vector_cSkaBlendSequenceItem_reserve(void);
#endif /* merge_units */
int std_vector_cSkaBlendSequenceItem_reserve(); /* merge_units */

extern void std_vector_deleter_cSkaBlendSequenceItem_clear(int);

void std_vector_imp_cSkaBlendSequenceItem_clear(int a0) {
    std_vector_deleter_cSkaBlendSequenceItem_clear(a0);
}

void cArray_cSkaBlendSequenceItem_ReserveActual(void) {
    std_vector_cSkaBlendSequenceItem_reserve();
}
static inline void merge_flush_func_001F4330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4330 */

/* merge_units: begin func_001F4350 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern void cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(void* dst, void* src);
#endif /* merge_units */
FloatPair * cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(); /* merge_units */


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

/* merge_units: begin func_001F4440 */
#pragma push /* merge_units */
FloatPair* cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

FloatPair* cSkaBlendSequenceExtents_ctor_float_float(FloatPair* self, float a, float b) {
    self->a = a;
    self->b = b;
    return self;
}
static inline void merge_flush_func_001F4440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4440 */

/* merge_units: begin func_001F4470 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

#if 0 /* merge_units */
extern void cLList_cSkaBlendSequenceItemPtr_ctor(void* obj);
#endif /* merge_units */
void * cLList_cSkaBlendSequenceItemPtr_ctor(); /* merge_units */


/* Runs cLList_cSkaBlendSequenceItemPtr_ctor on obj and returns obj. */
void* cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void* obj) {
    cLList_cSkaBlendSequenceItemPtr_ctor(obj);
    return obj;
}

#pragma pop
static inline void merge_flush_func_001F4470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4470 */

/* merge_units: begin func_001F44B0 */
#pragma push /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_ctor(void* self);

#pragma optimization_level 1
/* Calls std_list_cSkaBlendSequenceItemPtr_ctor on self and returns self (unit built at -O1). */
void* cLList_cSkaBlendSequenceItemPtr_ctor(void* self)
{
    std_list_cSkaBlendSequenceItemPtr_ctor(self);
    return self;
}
#pragma optimization_level reset
static inline void merge_flush_func_001F44B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F44B0 */
