/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern ListIter* List_InsertBefore(ListIter* out, LinkList* list, ListIter* pos, int* value);

/* Inserts *value at the back of the list (before the header node). */
ListIter* List_PushBack_132E20(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = &list->header;
    return List_InsertBefore(&result, list, &pos, value);
}
