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

extern int func_00439670(void);
extern int func_0043B410(Map* m, int node);     /* frees a subtree */

void func_0043B180(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_0043B190(int a0) {
    func_00439670();
    return a0;
}

/* clear(): frees all nodes and resets the map to empty. */
void Map_Clear(Map* m) {
    int root = m->head;

    if (root != 0) {
        func_0043B410(m, root);
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
DEFINE_TREE_ERASE_ITER(func_0043B200, func_0013C800, D_004BFDB0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0043B200 */
