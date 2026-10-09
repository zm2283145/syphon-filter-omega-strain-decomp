/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int List_InsertBefore(int** out, StdList* list, int** pos, int value);
extern int func_003EEE70(int owner, IfElement* elem);

/* list.push_back(value): insert before the sentinel. */
int func_003E8E80(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return List_InsertBefore(&it.result, list, &it.pos, value);
}

/* Forward the element to func_003EEE70 on its owner. */
int func_003E8EB0(IfElement* elem) {
    return func_003EEE70(elem->owner, elem);
}
