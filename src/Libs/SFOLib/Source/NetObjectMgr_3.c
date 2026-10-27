/*
 * main/NetObjectMgr: 2 files, 0042D770-0042D790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042D770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* cAssocArray_int_cMessagePtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void std_map_int_cMessagePtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042D770 */

/* merge_units: begin func_0042D790 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "net_transfer_types.h"
#include "alloc_guard.h"

extern "C" {
extern RbTree D_00582700;
extern char D_00582730[];
extern char D_004BFB00[];
extern char D_004D9300[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void std_tree_pair_int_value_compare_insert_one_pairR_3(TransferReferenceInsertResult* result, RbTree* tree,
                   const TransferReferenceValue* value);
void cMessage_ctor_cMessageNameR(TransferNotice* event, const void* descriptor);
void QueueMessage_cMessageR_cSystemP_int(TransferNotice* event, cGOBJ* object, int flags);
void cMessage_dtor(TransferNotice* event, int flags);
void std_tree_pair_int_value_compare_find_uintR_2(TransferReferenceIterator* result, RbTree* tree, const GobjId* id);
TransferReferenceIterator std_map_int_tNetActivateTerrainObjectPtr_end(RbTree* tree);
void cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void std_tree_pair_int_value_compare_erase_tree_4(RbTree* tree, TransferReferenceIterator* position);
}

static inline const GobjId& reference_id(cGOBJ* object, GobjId& invalid)
{
    if (object)
        return ((GobjEntry*)object)->id;
    invalid.word = -1;
    return invalid;
}

/* Register an object reference and send its notice unless the controller handles it. */
extern "C" void cNetObjectMgr_TerrainActivation(cGOBJ* object)
{
    TransferReferenceInsertResult result;
    TransferReferenceValue value;
    TransferNotice notice;
    if (!((TransferObjectMethods*)object)->is_registered()) {
        TransferReference* reference;
        {
            AllocGuard guard;
            reference = (TransferReference*)cMemMan_Allocate(0, sizeof(TransferReference), D_004BFB00, 0x1BA);
        }
        GobjId invalid;
        if (reference) {
            reference->id.word = -1;
            reference->object = object;
            reference->id.word = reference_id(object, invalid).word;
        }
        value.id.word = ((GobjEntry*)object)->id.word;
        value.reference = reference;
        std_tree_pair_int_value_compare_insert_one_pairR_3(&result, &D_00582700, &value);
        bool handled = false;
        if (object->attached && ((TransferController*)object->attached)->manages_transfer())
            handled = true;
        if (!handled) {
            cMessage_ctor_cMessageNameR(&notice, D_00582730);
            notice.vtable = D_004D9300;
            notice.enabled = 1;
            notice.action = 2;
            QueueMessage_cMessageR_cSystemP_int(&notice, object, 1);
            notice.vtable = D_004D9300;
            cMessage_dtor(&notice, 0);
        }
    }
}

/* Release a registered object reference and erase its map entry. */
extern "C" void cNetObjectMgr_RemoveFromTerrainActivation(cGOBJ* object)
{
    GobjId key;
    TransferReferenceIterator end;
    TransferReferenceIterator found;
    key.word = ((GobjEntry*)object)->id.word;
    std_tree_pair_int_value_compare_find_uintR_2(&found, &D_00582700, &key);
    TransferReferenceNode* node = found.node;
    cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(&end, std_map_int_tNetActivateTerrainObjectPtr_end(&D_00582700));
    if ((node == end.node) ^ 1) {
        TransferReference* reference = node->reference;
        {
            AllocGuard guard;
            cMemMan_Deallocate(0, reference, D_004BFB00, 0x1A7);
        }
        TransferReferenceIterator position;
        position.node = node;
        std_tree_pair_int_value_compare_erase_tree_4(&D_00582700, &position);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0042D790 */
