/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* List_InsertBefore(Iter* out, Tree* t, Iter* hint, int value);

Word* func_0014AB70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014AB80(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* func_0014AB90(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return List_InsertBefore(&it[1], t, &it[0], value);
}

Word* func_0014ABC0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_0014ABD0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014ABE0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0014ABF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int func_0014AC00(Word* a, Word* b) {
    return (0U < (unsigned int)(a->value ^ b->value));
}

void func_0014AC20(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Linked-list iterator increment: follow node->next (+4). */
Iter* func_0014AC30(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}

/* Address of the node payload (+8). */
int* func_0014AC50(Iter* it) {
    return it->p + 2;
}

float* func_0014AC60(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_0014AC70(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_0014AC80(void* self) {
    return self;
}
