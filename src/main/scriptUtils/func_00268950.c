/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

Word* func_00268950(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_00268960(ListPos* a, ListPos* b) {
    return a->node != b->node;
}

void func_00268980(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* List iterator increment: node = node->next. */
ListPos* func_00268990(ListPos* it) {
    it->node = ((ListNode*)it->node)->next;
    return it;
}

/* List iterator dereference: address of the node's value. */
int* func_002689B0(ListPos* it) {
    return &((ListNode*)it->node)->value;
}

float* func_002689C0(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_002689D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002689E0(void* self) {
    return self;
}
