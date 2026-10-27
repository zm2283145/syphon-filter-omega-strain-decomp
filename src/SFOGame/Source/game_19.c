/*
 * SFOGame/Source/game: 1 file, 001313D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001313D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern ListIter* std_list_deleter_voidPtr_insert(ListIter* out, LinkList* list, ListIter* pos, int* value);
extern ListIter* std_list_cGOBJPtr_push_back(LinkList* list, int* value);
extern int cHud_SetOwner(int);

/* Inserts *value at the front of the list. */
ListIter* std_list_cCAMERA_GOBJPtr_push_front(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = list->first;
    return std_list_deleter_voidPtr_insert(&result, list, &pos, value);
}

/* Stores the actor in world +0xBC and registers actor->+0x30 (+0xC) with cHud_SetOwner. */
int cGameSystem_SetPlayer(char* world, char* actor) {
    *(char**)(world + 0xBC) = actor;
    return cHud_SetOwner(*(int*)(actor + 0x30) + 12);
}

/* Appends node to the list at world +0x9C. */
void cGameSystem_AddTeleport(char* world, int node) {
    int tmp;

    tmp = node;
    std_list_cGOBJPtr_push_back((LinkList*)(world + 0x9C), &tmp);
}

/* Inserts *value at the back of the list (before the header node). */
ListIter* std_list_cGOBJPtr_push_back(LinkList* list, int* value) {
    ListIter pos;
    ListIter result;

    pos.node = &list->header;
    return std_list_deleter_voidPtr_insert(&result, list, &pos, value);
}
static inline void merge_flush_func_001313D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001313D0 */
