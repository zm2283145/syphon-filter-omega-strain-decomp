/*
 * Matched functions (byte-identical with the retail executable).
 * Container/iterator helpers; original translation unit not identified yet.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* List_InsertBefore(L4Iter* out, Tree* t, L4Iter* pos, int* value);
L4Iter* func_003D27B0(Tree* t, int* value);

Word* func_003D2710(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_003D2720(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* Iterator increment. */
L4Iter* func_003D2740(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

/* Iterator dereference. */
int* func_003D2760(L4Iter* it) {
    return &it->node->value;
}

float* func_003D2770(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void* func_003D2780(void* self) {
    return self;
}

/* Inserts a value (by copy). */
void func_003D2790(Tree* t, int value) {
    int loc[1];

    loc[0] = value;
    func_003D27B0(t, loc);
}

/* Inserts *value using the word at +8 of the container as the position hint. */
L4Iter* func_003D27B0(Tree* t, int* value) {
    L4Iter it[2];

    it[0].node = (L4Node*)t->unk8;
    return List_InsertBefore(&it[1], t, &it[0], value);
}
