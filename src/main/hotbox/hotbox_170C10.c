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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170C10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170C10 */

/* merge_units: begin func_00170D30 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; int unk8; } Container;
typedef struct { char pad[0x28]; Container list; } Obj170;

extern Container D_004EE688;
extern void ObjectList_EraseRange(int* out, Container* self, int* value, int** where);

/* Calls ObjectList_EraseRange for the global container and for the object's container at +0x28. */
void func_00170D30(Obj170* self)
{
    int* where2;
    int value2;
    int result2;
    int* where;
    int value;
    int result;
    where = &D_004EE688.unk4;
    value = D_004EE688.unk8;
    ObjectList_EraseRange(&result, &D_004EE688, &value, &where);
    where2 = &self->list.unk4;
    value2 = self->list.unk8;
    ObjectList_EraseRange(&result2, &self->list, &value2, &where2);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170D30 */
