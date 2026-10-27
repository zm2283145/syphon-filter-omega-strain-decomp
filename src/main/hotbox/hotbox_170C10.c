/*
 * main/hotbox: range (2 files, 00170C10-00170D30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "hotbox_types.h"

/* merge_units: begin func_00170C10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */


extern int std_list_deleter_voidPtr_insert(HotboxListIter* out, Tree* list, HotboxListIter* pos, int* value);

/* Inserts value with end() as the position hint; the result iterator is discarded. */
int std_list_cHotboxPtr_push_back(Tree* list, int* value) {
    HotboxListIter end;
    HotboxListIter result;

    end.node = (HotboxListNode*)&list->header;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}

Word* cLListIterator_cHotboxPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_2(HotboxListIter* a, HotboxListIter* b) {
    return a->node != b->node;
}

void cLList_cHotboxPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* ++it */
HotboxListIter* cLListIterator_cHotboxPtr_opInc(HotboxListIter* it) {
    it->node = it->node->next;
    return it;
}

/* &*it */
int* cLListIterator_cHotboxPtr_opMul(HotboxListIter* it) {
    return &it->node->value;
}

float* cLListIterator_cHotboxPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_cHotboxPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cHotboxPtr_ctor_void(void* self) {
    return self;
}

Word* std_list_cHotboxPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cHotboxPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}

void std_list_cHotboxPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* cLListIterator_cHotboxPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cHotboxPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170C10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170C10 */

/* merge_units: begin func_00170D30 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; int unk8; } Container;
typedef struct { char pad[0x28]; Container list; } Obj170;

extern Container g_HotboxList;
extern void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, Container* self, int* value, int** where);

/* Calls std_list_deleter_voidPtr_erase_listdeleter_listdeleter for the global container and for the object's container at +0x28. */
void cHotboxMan_ClearLists(Obj170* self)
{
    int* where2;
    int value2;
    int result2;
    int* where;
    int value;
    int result;
    where = &g_HotboxList.unk4;
    value = g_HotboxList.unk8;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&result, &g_HotboxList, &value, &where);
    where2 = &self->list.unk4;
    value2 = self->list.unk8;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&result2, &self->list, &value2, &where2);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170D30 */
