/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper and container accessors.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern SpecListPos* std_list_deleter_voidPtr_insert(SpecListPos* result, void* list, SpecListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
SpecListPos* std_list_cElementPtr_push_back_cElementPR_2(void* list, int* value) {
    SpecListPos end;
    SpecListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}

void std_list_cElementPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cElementPtr_ctor_listR_2(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cElementPtr_begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}
