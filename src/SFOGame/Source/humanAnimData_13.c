/*
 * SFOGame/Source/humanAnimData: 7 files, 001F33E0-001F3580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F33E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

#if 0 /* merge_units */
extern void std_opNe_listR_listR_2(void);
#endif /* merge_units */
int std_opNe_listR_listR_2(); /* merge_units */


void opNe_cConstLListIteratorR_cConstLListIteratorR_3(void) {
    std_opNe_listR_listR_2();
}
static inline void merge_flush_func_001F33E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F33E0 */

/* merge_units: begin func_001F33F0 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int std_opNe_listdeleterR_listdeleterR(ListIter*, ListIter*);
extern ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* std_list_cSkaTransBLENDPtr_generic_iterator_1_opInc(ListIter*);
#if 0 /* merge_units */
extern void std_vector_cSkaTransBLEND_push_back(void);
#endif /* merge_units */
void std_vector_cSkaTransBLEND_push_back(); /* merge_units */



int std_opNe_listR_listR_2(ListIter* a, ListIter* b) {
    return std_opNe_listdeleterR_listdeleterR(a, b);
}

ListIter* cConstLListIterator_cSkaTransBLENDPtr_opInc(ListIter* it) {
    std_list_cSkaTransBLENDPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaTransBLENDPtr_generic_iterator_1_opInc(ListIter* it) {
    std_list_deleter_voidPtr_generic_iterator_1_opInc(it);
    return it;
}

void cArray_cSkaTransBLEND_PushBackActual(void) {
    std_vector_cSkaTransBLEND_push_back();
}
static inline void merge_flush_func_001F33F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F33F0 */

/* merge_units: begin func_001F3470 */
#pragma push /* merge_units */
extern int std_vector_imp_cSkaTransBLEND_push_back(ObjVec*, int);
extern char* std_vector_imp_cSkaTransBLEND_end_void(ObjVec*);
#if 0 /* merge_units */
extern char** std_vector_deleter_cSkaTransBLEND_data_void(ObjVec*);
#endif /* merge_units */
char * * std_vector_deleter_cSkaTransBLEND_data_void(); /* merge_units */


extern int std_vector_imp_cSkaTransBLEND_insert(ObjVec*, char*, int, int);

void std_vector_cSkaTransBLEND_push_back(ObjVec* v, int value) {
    std_vector_imp_cSkaTransBLEND_push_back(v, value);
}

/* Append one element at the end. */
int std_vector_imp_cSkaTransBLEND_push_back(ObjVec* v, int value) {
    return std_vector_imp_cSkaTransBLEND_insert(v, std_vector_imp_cSkaTransBLEND_end_void(v), 1, value);
}

/* End pointer for 36-byte elements. */
char* std_vector_imp_cSkaTransBLEND_end_void(ObjVec* v) {
    char** data;
    int count;

    data = std_vector_deleter_cSkaTransBLEND_data_void(v);
    count = v->count;
    return *data + count * 36;
}
static inline void merge_flush_func_001F3470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3470 */

/* merge_units: begin func_001F3510 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaTransBLENDPtr_generic_iterator_1_opMul(void);
#endif /* merge_units */
char * std_list_cSkaTransBLENDPtr_generic_iterator_1_opMul(); /* merge_units */


/* Address of the data pointer. */
char** std_vector_deleter_cSkaTransBLEND_data_void(ObjVec* v) {
    return &v->data;
}

void cConstLListIterator_cSkaTransBLENDPtr_opMul(void) {
    std_list_cSkaTransBLENDPtr_generic_iterator_1_opMul();
}
static inline void merge_flush_func_001F3510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3510 */

/* merge_units: begin func_001F3530 */
#pragma push /* merge_units */
extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaTransBLENDPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}
static inline void merge_flush_func_001F3530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3530 */

/* merge_units: begin func_001F3540 */
#pragma push /* merge_units */
typedef struct { int value; } Temp;
extern void std_list_cSkaTransBLENDPtr_end(Temp* out);
#if 0 /* merge_units */
extern void cConstLListIterator_cSkaTransBLENDPtr_ctor(void* self, Temp* in);
#endif /* merge_units */
int cConstLListIterator_cSkaTransBLENDPtr_ctor(); /* merge_units */


/* Builds a temporary with std_list_cSkaTransBLENDPtr_end and applies it to self. */
void cLList_cSkaTransBLENDPtr_End(void* self)
{
    Temp t;
    std_list_cSkaTransBLENDPtr_end(&t);
    cConstLListIterator_cSkaTransBLENDPtr_ctor(self, &t);
}
static inline void merge_flush_func_001F3540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3540 */

/* merge_units: begin func_001F3580 */
#pragma push /* merge_units */
extern int std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listR(int);

int cConstLListIterator_cSkaTransBLENDPtr_ctor(int a0) {
    std_list_cSkaTransBLENDPtr_generic_iterator_1_ctor_listR(a0);
    return a0;
}
static inline void merge_flush_func_001F3580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3580 */
