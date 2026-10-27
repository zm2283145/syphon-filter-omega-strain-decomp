/*
 * SFOGame/Source/humanAnimData: 3 files, 001F2C90-001F2DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2C90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
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
extern void std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(void);

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
