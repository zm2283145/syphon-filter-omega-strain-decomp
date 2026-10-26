/*
 * main/NPCInfoObject: 5 files, 00436B90-00436C90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00436B90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

void std_list_tNPCInfoPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_00436B90 */

/* merge_units: begin func_00436BA0 */
#pragma push /* merge_units */
extern int D_00582A68;
extern void operator_delete(void* allocation);

/* Release a shared NPC node and optionally destroy it. */
int* cNPCInfoObject_dtor(int* node, short deleteFlag)
{
    if (node) {
        D_00582A68--;
        if (deleteFlag > 0)
            operator_delete(node);
    }
    return node;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00436BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00436BA0 */

/* merge_units: begin func_00436C00 */
#pragma push /* merge_units */
typedef struct NPCInfoObject NPCInfoObject;

extern unsigned char D_00582778;
extern void cNPCInfoObject_Setup(NPCInfoObject* self);

/* Ensure shared NPC information is initialized and increment its user count. */
NPCInfoObject* cNPCInfoObject_ctor(NPCInfoObject* self) {
    if (D_00582778 == 0) {
        cNPCInfoObject_Setup(self);
    }
    D_00582A68++;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00436C00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00436C00 */

/* merge_units: begin func_00436C50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern void std_tree_pair_tNPCInfoPtr_value_compare_destroy(Tree* t, int root);

/* Tree clear: frees the nodes under the root and resets to empty. */
void std_tree_pair_tNPCInfoPtr_value_compare_clear(Tree* t) {
    if (t->header != 0) {
        std_tree_pair_tNPCInfoPtr_value_compare_destroy(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00436C50 */

/* merge_units: begin func_00436C90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_erase_iter.h"

extern "C" { char D_004BFD10[] = "allocator.hh"; }
DEFINE_TREE_ERASE_ITER(std_tree_pair_tNPCInfoPtr_value_compare_erase, std_red_black_tree_1_balance_erase, D_004BFD10, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00436C90 */
