/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int List_InsertBefore(HotboxListIter* out, Tree* list, HotboxListIter* pos, int* value);

/* Inserts value with end() as the position hint; the result iterator is discarded. */
int func_00170C10(Tree* list, int* value) {
    HotboxListIter end;
    HotboxListIter result;

    end.node = (HotboxListNode*)&list->header;
    return List_InsertBefore(&result, list, &end, value);
}

Word* func_00170C40(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_00170C50(HotboxListIter* a, HotboxListIter* b) {
    return a->node != b->node;
}

void func_00170C70(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* ++it */
HotboxListIter* func_00170C80(HotboxListIter* it) {
    it->node = it->node->next;
    return it;
}

/* &*it */
int* func_00170CA0(HotboxListIter* it) {
    return &it->node->value;
}

float* func_00170CB0(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_00170CC0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00170CD0(void* self) {
    return self;
}

Word* func_00170CE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00170CF0(Word* dst, Word* src) {
    dst->value = src->value;
}

void func_00170D00(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_00170D10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00170D20(Iter* out, Tree* t) {
    out->p = &t->header;
}
