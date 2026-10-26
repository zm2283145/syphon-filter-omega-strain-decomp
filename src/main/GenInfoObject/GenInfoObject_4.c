/*
 * main/GenInfoObject: 2 files, 0043B180-0043B200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043B180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cGenInfoObject_Setup(void);
extern int std_tree_pair_tGenInfoPtr_value_compare_destroy(Map* m, int node);     /* frees a subtree */

void std_list_tGenInfoPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int cGenInfoObject_ctor(int a0) {
    cGenInfoObject_Setup();
    return a0;
}

/* clear(): frees all nodes and resets the map to empty. */
void Map_Clear(Map* m) {
    int root = m->head;

    if (root != 0) {
        std_tree_pair_tGenInfoPtr_value_compare_destroy(m, root);
        m->count = 0;
        m->head = 0;
        m->hp = &m->head;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043B180 */

/* merge_units: begin func_0043B200 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_erase_iter.h"

extern "C" { char D_004BFDB0[] = "allocator.hh"; }
DEFINE_TREE_ERASE_ITER(std_tree_pair_tGenInfoPtr_value_compare_erase, std_red_black_tree_1_balance_erase, D_004BFDB0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0043B200 */
