/*
 * main/gobj: 2 files, 003D2710-003D27E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container/iterator helpers; original translation unit not identified yet.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* std_list_deleter_voidPtr_insert(L4Iter* out, Tree* t, L4Iter* pos, int* value);
L4Iter* std_list_cAnimTexturePtr_push_front(Tree* t, int* value);

Word* cLListIterator_cAnimTexturePtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_10(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* Iterator increment. */
L4Iter* cLListIterator_cAnimTexturePtr_opInc(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

/* Iterator dereference. */
int* cLListIterator_cAnimTexturePtr_opMul(L4Iter* it) {
    return &it->node->value;
}

float* cLListIterator_cAnimTexturePtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void* cLListIterator_cAnimTexturePtr_ctor_void(void* self) {
    return self;
}

/* Inserts a value (by copy). */
void cAnimTexMan_Add(Tree* t, int value) {
    int loc[1];

    loc[0] = value;
    std_list_cAnimTexturePtr_push_front(t, loc);
}

/* Inserts *value using the word at +8 of the container as the position hint. */
L4Iter* std_list_cAnimTexturePtr_push_front(Tree* t, int* value) {
    L4Iter it[2];

    it[0].node = (L4Node*)t->unk8;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D2710 */

/* merge_units: begin func_003D27E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; void* vt; } TC8E0;
extern void * const D_004E00A8[];
extern void std_list_cAnimTexturePtr_dtor(void* self, short del);
extern void operator_delete(void* p);
TC8E0* cAnimTexMan_dtor(TC8E0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E00A8);
        if (self)
            std_list_cAnimTexturePtr_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E00A8[3] = { (void*)0x0, (void*)0x0, (void*)cAnimTexMan_dtor };
#pragma pop /* merge_units */
/* merge_units: end func_003D27E0 */
