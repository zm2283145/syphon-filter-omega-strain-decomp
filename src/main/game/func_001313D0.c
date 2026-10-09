/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern ListIter* List_InsertBefore(ListIter* out, LinkList* list, ListIter* pos, int* value);
extern ListIter* List_PushBack(LinkList* list, int* value);
extern int func_002426D0(int);

/* Inserts *value at the front of the list. */
ListIter* List_PushFront(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = list->first;
    return List_InsertBefore(&result, list, &pos, value);
}

/* Stores the actor in world +0xBC and registers actor->+0x30 (+0xC) with func_002426D0. */
int World_RegisterActor(char* world, char* actor) {
    *(char**)(world + 0xBC) = actor;
    return func_002426D0(*(int*)(actor + 0x30) + 12);
}

/* Appends node to the list at world +0x9C. */
void World_RegisterNode(char* world, int node) {
    int tmp;

    tmp = node;
    List_PushBack((LinkList*)(world + 0x9C), &tmp);
}

/* Inserts *value at the back of the list (before the header node). */
ListIter* List_PushBack(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = &list->header;
    return List_InsertBefore(&result, list, &pos, value);
}
