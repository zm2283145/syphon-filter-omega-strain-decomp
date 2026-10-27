/*
 * SFOGame/Source/game: 1 file, 00132E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00132E20 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00132E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00132E20 */
