/*
 * SFOGame/Source/humanAnimData: 7 files, 001F2ED0-001F3010
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2ED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_end_void_2(Word*, int);
#if 0 /* merge_units */
extern Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);
#endif /* merge_units */
Word * std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(); /* merge_units */



Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkaSwitchItemPtr_end(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_end_void_2(&tmp, a1);
    std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}
static inline void merge_flush_func_001F2ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2ED0 */

/* merge_units: begin func_001F2F20 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern Word* std_list_deleter_voidPtr_generic_iterator_1_ctor(Word*, Word*);
#endif /* merge_units */
#define std_list_deleter_voidPtr_generic_iterator_1_ctor(a0, a1) (std_list_deleter_voidPtr_generic_iterator_1_ctor((a0), (a1))) /* merge_units */



Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, &tmp);
    return dst;
}
#undef std_list_deleter_voidPtr_generic_iterator_1_ctor /* merge_units */
static inline void merge_flush_func_001F2F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2F20 */

/* merge_units: begin func_001F2F50 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaSwitchItemPtr_begin(int* out, int a1);
#endif /* merge_units */
void std_list_cSkaSwitchItemPtr_begin(); /* merge_units */


extern void cConstLListIterator_cSkaSwitchItemPtr_ctor(void* self, int* value);

/* Fetches a value with std_list_cSkaSwitchItemPtr_begin into a temporary and passes it to cConstLListIterator_cSkaSwitchItemPtr_ctor. */
void cLList_cSkaSwitchItemPtr_Begin(void* self, int a1)
{
    int value;
    std_list_cSkaSwitchItemPtr_begin(&value, a1);
    cConstLListIterator_cSkaSwitchItemPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F2F50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2F50 */

/* merge_units: begin func_001F2F90 */
#pragma push /* merge_units */
extern void std_list_deleter_voidPtr_begin_void_2(Word*, int);
#if 0 /* merge_units */
extern Word* std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(Word*, int);
#endif /* merge_units */
#define std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(a0, a1) (std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter((a0), (a1))) /* merge_units */


extern void std_vector_cSkaSwitchItem_clear(void);
#if 0 /* merge_units */
extern void std_vector_imp_cSkaSwitchItem_clear(void);
#endif /* merge_units */
void std_vector_imp_cSkaSwitchItem_clear(); /* merge_units */



void std_list_cSkaSwitchItemPtr_begin(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_begin_void_2(&tmp, a1);
    std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

void cArray_cSkaSwitchItem_Clear(void) {
    std_vector_cSkaSwitchItem_clear();
}

void std_vector_cSkaSwitchItem_clear(void) {
    std_vector_imp_cSkaSwitchItem_clear();
}
#undef std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listdeleter /* merge_units */
static inline void merge_flush_func_001F2F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2F90 */

/* merge_units: begin func_001F2FF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_vector_cSkaSwitchItem_reserve(void);
#endif /* merge_units */
int std_vector_cSkaSwitchItem_reserve(); /* merge_units */

extern void std_vector_deleter_cSkaSwitchItem_clear(int);

void std_vector_imp_cSkaSwitchItem_clear(int a0) {
    std_vector_deleter_cSkaSwitchItem_clear(a0);
}

void cArray_cSkaSwitchItem_ReserveActual(void) {
    std_vector_cSkaSwitchItem_reserve();
}
static inline void merge_flush_func_001F2FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2FF0 */

/* merge_units: begin func_001F3010 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int std_list_imp_voidPtr_size(void);
#endif /* merge_units */
int std_list_imp_voidPtr_size(); /* merge_units */


extern int std_vector_imp_cSkaSwitchItem_reserve(int, int);

int std_vector_cSkaSwitchItem_reserve(int a0, int a1) {
    return std_vector_imp_cSkaSwitchItem_reserve(a0, a1);
}

int cLList_cSkaSwitchItemPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}
static inline void merge_flush_func_001F3010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3010 */

/* merge_units: begin func_001F3030 */
#pragma push /* merge_units */
extern int* std_list_deleter_voidPtr_sz_void_2(void* obj);

/* Returns the int pointed to by std_list_deleter_voidPtr_sz_void_2's result. */
int std_list_imp_voidPtr_size(void* obj) {
    return *std_list_deleter_voidPtr_sz_void_2(obj);
}
static inline void merge_flush_func_001F3030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3030 */
