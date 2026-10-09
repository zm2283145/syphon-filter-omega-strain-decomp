/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper and container accessors.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern SpecListPos* List_InsertBefore(SpecListPos* result, void* list, SpecListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
SpecListPos* func_002359A0(void* list, int* value) {
    SpecListPos end;
    SpecListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

void func_002359D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002359E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002359F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
