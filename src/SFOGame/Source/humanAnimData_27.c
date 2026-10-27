/*
 * SFOGame/Source/humanAnimData: 4 files, 001F35B0-001F36F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F35B0 */
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
extern Word* std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listdeleter(Word*, int);

Word* std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listR(Word* dst, Word* src) {
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, src);
    return dst;
}

void std_list_cSkaTransBLENDPtr_end(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_end_void_2(&tmp, a1);
    std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

Word* std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listdeleter(Word* dst, int value) {
    Word tmp;

    tmp.value = value;
    std_list_deleter_voidPtr_generic_iterator_1_ctor(dst, &tmp);
    return dst;
}
static inline void merge_flush_func_001F35B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F35B0 */

/* merge_units: begin func_001F3650 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaTransBLENDPtr_begin(int* out);
#endif /* merge_units */
void std_list_cSkaTransBLENDPtr_begin(); /* merge_units */

extern void cConstLListIterator_cSkaTransBLENDPtr_ctor(void* self, int* value);

/* Fetches a value via std_list_cSkaTransBLENDPtr_begin and applies it to self via cConstLListIterator_cSkaTransBLENDPtr_ctor. */
void cLList_cSkaTransBLENDPtr_Begin(void* self) {
    int value;
    std_list_cSkaTransBLENDPtr_begin(&value);
    cConstLListIterator_cSkaTransBLENDPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F3650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3650 */

/* merge_units: begin func_001F3690 */
#pragma push /* merge_units */
extern void std_list_deleter_voidPtr_begin_void_2(Word*, int);
extern void std_vector_cSkaTransBLEND_clear(void);
#if 0 /* merge_units */
extern void std_vector_imp_cSkaTransBLEND_clear(void);
#endif /* merge_units */
void std_vector_imp_cSkaTransBLEND_clear(); /* merge_units */


void std_list_cSkaTransBLENDPtr_begin(Word* self, int a1) {
    Word tmp;

    std_list_deleter_voidPtr_begin_void_2(&tmp, a1);
    std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listdeleter(self, tmp.value);
}

void cArray_cSkaTransBLEND_Clear(void) {
    std_vector_cSkaTransBLEND_clear();
}

void std_vector_cSkaTransBLEND_clear(void) {
    std_vector_imp_cSkaTransBLEND_clear();
}
static inline void merge_flush_func_001F3690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3690 */

/* merge_units: begin func_001F36F0 */
#pragma push /* merge_units */
extern void std_vector_cSkaTransBLEND_reserve(void);
extern void std_vector_deleter_cSkaTransBLEND_clear(int);

void std_vector_imp_cSkaTransBLEND_clear(int a0) {
    std_vector_deleter_cSkaTransBLEND_clear(a0);
}

void cArray_cSkaTransBLEND_ReserveActual(void) {
    std_vector_cSkaTransBLEND_reserve();
}
static inline void merge_flush_func_001F36F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F36F0 */
