/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int List_InsertBefore(int** out, StdList* list, int** pos, int value);
extern int IeScreen_RemoveElement(int owner, IfElement* elem);

/* list.push_back(value): insert before the sentinel. */
int TextManager_AddText(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return List_InsertBefore(&it.result, list, &it.pos, value);
}

/* Forward the element to IeScreen_RemoveElement on its owner. */
int IeElement_Release(IfElement* elem) {
    return IeScreen_RemoveElement(elem->owner, elem);
}
