/*
 * Matched functions (byte-identical with the retail executable).
 * List / vector helpers.
 */

#include "types.h"

extern int std_list_deleter_voidPtr_insert(Iter* result, List* list, Iter* pos, int value);

/* push_back(value): inserts before the end sentinel at list+4. */
int std_list_CrateSavePtr_push_back(List* list, int value) {
    Iter it[2];   /* it[0] = end position, it[1] = returned iterator */
    it[0].p = (int*)&list->first;
    return std_list_deleter_voidPtr_insert(&it[1], list, &it[0], value);
}

int* std_vector_cBackpackPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
