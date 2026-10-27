/*
 * SFOGame/Source/humanAnimData: 8 files, 001F2C80-001F2EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2C80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

#if 0 /* merge_units */
extern void std_opNe_listR_listR(void);
#endif /* merge_units */
int std_opNe_listR_listR(); /* merge_units */


void opNe_cConstLListIteratorR_cConstLListIteratorR_2(void) {
    std_opNe_listR_listR();
}
static inline void merge_flush_func_001F2C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2C80 */

/* merge_units: begin func_001F2C90 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int std_opNe_listdeleterR_listdeleterR(ListIter*, ListIter*);
extern ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter*);
#if 0 /* merge_units */
extern void std_vector_cSkaSwitchItem_push_back(void);
#endif /* merge_units */
void std_vector_cSkaSwitchItem_push_back(); /* merge_units */



int std_opNe_listR_listR(ListIter* a, ListIter* b) {
    return std_opNe_listdeleterR_listdeleterR(a, b);
}

/* Iterator inequality. */
int std_opNe_listdeleterR_listdeleterR(ListIter* a, ListIter* b) {
    return ((unsigned int)(0) < (unsigned int)(((int)a->node ^ (int)b->node)));
}

ListIter* cConstLListIterator_cSkaSwitchItemPtr_opInc(ListIter* it) {
    std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter* it) {
    std_list_deleter_voidPtr_generic_iterator_1_opInc(it);
    return it;
}

/* Iterator increment: advance to the next node. */
ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter* it) {
    it->node = it->node->next;
    return it;
}

void cArray_cSkaSwitchItem_PushBackActual(void) {
    std_vector_cSkaSwitchItem_push_back();
}
static inline void merge_flush_func_001F2C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2C90 */

/* merge_units: begin func_001F2D50 */
#pragma push /* merge_units */
extern int std_vector_imp_cSkaSwitchItem_push_back(ObjVec*, int);
extern char* std_vector_imp_cSkaSwitchItem_end(ObjVec*);
#if 0 /* merge_units */
extern char** std_vector_deleter_cSkaSwitchItem_data(ObjVec*);
#endif /* merge_units */
char * * std_vector_deleter_cSkaSwitchItem_data(); /* merge_units */


extern int std_vector_imp_cSkaSwitchItem_insert(ObjVec*, char*, int, int);

void std_vector_cSkaSwitchItem_push_back(ObjVec* v, int value) {
    std_vector_imp_cSkaSwitchItem_push_back(v, value);
}

/* Append one element at the end. */
int std_vector_imp_cSkaSwitchItem_push_back(ObjVec* v, int value) {
    return std_vector_imp_cSkaSwitchItem_insert(v, std_vector_imp_cSkaSwitchItem_end(v), 1, value);
}

/* End pointer for 20-byte elements. */
char* std_vector_imp_cSkaSwitchItem_end(ObjVec* v) {
    char** data;
    int count;

    data = std_vector_deleter_cSkaSwitchItem_data(v);
    count = v->count;
    return *data + count * 20;
}
static inline void merge_flush_func_001F2D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2D50 */

/* merge_units: begin func_001F2DF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(void);
#endif /* merge_units */
char * std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(); /* merge_units */


/* Address of the data pointer. */
char** std_vector_deleter_cSkaSwitchItem_data(ObjVec* v) {
    return &v->data;
}

void cConstLListIterator_cSkaSwitchItemPtr_opMul(void) {
    std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul();
}
static inline void merge_flush_func_001F2DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2DF0 */

/* merge_units: begin func_001F2E10 */
#pragma push /* merge_units */
extern char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16*);

char* std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(Iter16* it) {
    return std_list_deleter_voidPtr_generic_iterator_1_opMul(it);
}

/* Address 8 bytes past the pointed-to node. */
char* std_list_deleter_voidPtr_generic_iterator_1_opMul(Iter16* it) {
    return it->p + 8;
}
static inline void merge_flush_func_001F2E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2E10 */

/* merge_units: begin func_001F2E30 */
#pragma push /* merge_units */
extern void std_list_cSkaSwitchItemPtr_end(int* out);
#if 0 /* merge_units */
extern void cConstLListIterator_cSkaSwitchItemPtr_ctor(void* self, int* value);
#endif /* merge_units */
void * cConstLListIterator_cSkaSwitchItemPtr_ctor(); /* merge_units */


/* Fetches a value with std_list_cSkaSwitchItemPtr_end and passes it to cConstLListIterator_cSkaSwitchItemPtr_ctor. */
void cLList_cSkaSwitchItemPtr_End(void* self)
{
    int value;
    std_list_cSkaSwitchItemPtr_end(&value);
    cConstLListIterator_cSkaSwitchItemPtr_ctor(self, &value);
}
static inline void merge_flush_func_001F2E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2E30 */

/* merge_units: begin func_001F2E70 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listR(void* s);
#endif /* merge_units */
int std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listR(); /* merge_units */

void* cConstLListIterator_cSkaSwitchItemPtr_ctor(void* s) { std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listR(s); return s; }
static inline void merge_flush_func_001F2E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2E70 */

/* merge_units: begin func_001F2EA0 */
#pragma push /* merge_units */
extern int std_list_deleter_voidPtr_generic_iterator_1_ctor(int, int);

int std_list_cSkaSwitchItemPtr_generic_iterator_1_ctor_listR(int a0, int a1) {
    std_list_deleter_voidPtr_generic_iterator_1_ctor(a0, a1);
    return a0;
}
static inline void merge_flush_func_001F2EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2EA0 */
