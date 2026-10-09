/*
 * Matched functions (byte-identical with the retail executable).
 * List / vector helpers.
 */

#include "types.h"

extern int List_InsertBefore(Iter* result, List* list, Iter* pos, int value);

/* push_back(value): inserts before the end sentinel at list+4. */
int func_00256D50(List* list, int value) {
    Iter it[2];   /* it[0] = end position, it[1] = returned iterator */
    it[0].p = (int*)&list->first;
    return List_InsertBefore(&it[1], list, &it[0], value);
}

int* func_00256D80(PtrVec* v, int i) {
    return v->data + i;
}
