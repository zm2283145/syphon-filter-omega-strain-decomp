/*
 * main/motionManager: 3 files, 0040F9F0-0040FB40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F9F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc_11)
#pragma pop /* merge_units */
/* merge_units: end func_0040F9F0 */

/* merge_units: begin func_0040FAA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BEDE8[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_12(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004BEDE8, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040FAA0 */

/* merge_units: begin func_0040FB40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern void World_FreePendingTree(Tree* t, int root);

/* Address of the tree header (end()). */
int* func_0040FB40(Tree* t) {
    return &t->header;
}

void* func_0040FB50(void* self) {
    return self;
}

/* Erases every node of the tree and resets it to empty. */
void World_ClearPending(Tree* t) {
    if (t->header != 0) {
        World_FreePendingTree(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}

Map* MotionManager_Ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040FB40 */
