/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "texman_types.h"

extern TexListIter* std_list_deleter_int_insert(TexListIter* result, void* list, TexListIter* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
TexListIter* cLList_int_PushBackActual(void* list, int* value) {
    TexListIter end;
    TexListIter result;

    end.node = (TexListNode*)((char*)list + 4);
    return std_list_deleter_int_insert(&result, list, &end, value);
}
