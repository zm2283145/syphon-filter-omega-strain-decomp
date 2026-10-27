/*
 * SFOGame/Source/humanAnimData: 4 files, 001F41F0-001F4330
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
extern void std_vector_cSkaBlendSequenceItem_reserve(void);
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
