/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern ListIter* std_list_deleter_voidPtr_insert(ListIter* out, LinkList* list, ListIter* pos, int* value);

/* Inserts *value at the back of the list (before the header node). */
ListIter* cLList_cScenePtr_PushBackActual(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = &list->header;
    return std_list_deleter_voidPtr_insert(&result, list, &pos, value);
}
