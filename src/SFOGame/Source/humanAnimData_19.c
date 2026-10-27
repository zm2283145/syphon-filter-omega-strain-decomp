/*
 * SFOGame/Source/humanAnimData: 7 files, 001F4020-001F41C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F4020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

#if 0 /* merge_units */
extern void std_opNe_listR_listR_3(void);
#endif /* merge_units */
int std_opNe_listR_listR_3(); /* merge_units */


void opNe_cConstLListIteratorR_cConstLListIteratorR_4(void) {
    std_opNe_listR_listR_3();
}
static inline void merge_flush_func_001F4020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4020 */

/* merge_units: begin func_001F4030 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int std_opNe_listdeleterR_listdeleterR(ListIter*, ListIter*);
extern ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter*);
#if 0 /* merge_units */
extern void std_vector_cSkaBlendSequenceItem_push_back(void);
#endif /* merge_units */
void std_vector_cSkaBlendSequenceItem_push_back(); /* merge_units */



int std_opNe_listR_listR_3(ListIter* a, ListIter* b) {
    return std_opNe_listdeleterR_listdeleterR(a, b);
}

ListIter* cConstLListIterator_cSkaBlendSequenceItemPtr_opInc(ListIter* it) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter* it) {
    std_list_deleter_voidPtr_generic_iterator_1_opInc(it);
    return it;
}

void cArray_cSkaBlendSequenceItem_PushBackActual(void) {
    std_vector_cSkaBlendSequenceItem_push_back();
}
static inline void merge_flush_func_001F4030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4030 */

/* merge_units: begin func_001F40B0 */
#pragma push /* merge_units */
extern int std_vector_imp_cSkaBlendSequenceItem_push_back(ObjVec*, int);
extern char* std_vector_imp_cSkaBlendSequenceItem_end_void(ObjVec*);
#if 0 /* merge_units */
extern char** std_vector_deleter_cSkaBlendSequenceItem_data_void(ObjVec*);
#endif /* merge_units */
char * * std_vector_deleter_cSkaBlendSequenceItem_data_void(); /* merge_units */


extern int std_vector_imp_cSkaBlendSequenceItem_insert(ObjVec*, char*, int, int);

void std_vector_cSkaBlendSequenceItem_push_back(ObjVec* v, int value) {
    std_vector_imp_cSkaBlendSequenceItem_push_back(v, value);
}

/* Append one element at the end. */
int std_vector_imp_cSkaBlendSequenceItem_push_back(ObjVec* v, int value) {
    return std_vector_imp_cSkaBlendSequenceItem_insert(v, std_vector_imp_cSkaBlendSequenceItem_end_void(v), 1, value);
}

/* End pointer for 12-byte elements. */
char* std_vector_imp_cSkaBlendSequenceItem_end_void(ObjVec* v) {
    char** data;
    int count;

    data = std_vector_deleter_cSkaBlendSequenceItem_data_void(v);
    count = v->count;
    return *data + count * 12;
}
static inline void merge_flush_func_001F40B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F40B0 */

/* merge_units: begin func_001F4150 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul(void);
#endif /* merge_units */
char * std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul(); /* merge_units */


/* Address of the data pointer. */
char** std_vector_deleter_cSkaBlendSequenceItem_data_void(ObjVec* v) {
    return &v->data;
}

void cConstLListIterator_cSkaBlendSequenceItemPtr_opMul(void) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul();
}
static inline void merge_flush_func_001F4150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4150 */

/* merge_units: begin func_001F4170 */
#pragma push /* merge_units */
extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}
static inline void merge_flush_func_001F4170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4170 */

/* merge_units: begin func_001F4180 */
#pragma push /* merge_units */
extern void std_list_cSkaBlendSequenceItemPtr_end(int*);
#if 0 /* merge_units */
extern void cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(void*, int*);
#endif /* merge_units */
int cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(); /* merge_units */


/* Fetches a value via std_list_cSkaBlendSequenceItemPtr_end and passes it to cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value). */
void cLList_cSkaBlendSequenceItemPtr_End(void* self) {
    int value;
    std_list_cSkaBlendSequenceItemPtr_end(&value);
    cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F4180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F4180 */

/* merge_units: begin func_001F41C0 */
#pragma push /* merge_units */
extern int std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listR(int);

int cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(int a0) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_ctor_listR(a0);
    return a0;
}
static inline void merge_flush_func_001F41C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F41C0 */
