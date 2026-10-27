/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int std_list_deleter_voidPtr_insert(int** out, StdList* list, int** pos, int value);
extern int cInterfaceModel_DestroyInstance(int owner, IfElement* elem);

/* list.push_back(value): insert before the sentinel. */
int cLList_cTextAreaPtr_PushBackActual(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return std_list_deleter_voidPtr_insert(&it.result, list, &it.pos, value);
}

/* Forward the element to cInterfaceModel_DestroyInstance on its owner. */
int cInterfaceElement_Destroy(IfElement* elem) {
    return cInterfaceModel_DestroyInstance(elem->owner, elem);
}
