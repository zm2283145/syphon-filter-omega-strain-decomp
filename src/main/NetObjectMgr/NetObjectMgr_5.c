/*
 * main/NetObjectMgr: 4 files, 0042EAF0-0042EFF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042EAF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* begin(): iterator at the leftmost node. */
void std_tree_pair_int_value_compare_begin_void_3(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* begin(): iterator at the leftmost node. */
void std_map_int_cMessagePtr_begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* begin(): iterator at the leftmost node. */
void std_tree_pair_int_value_compare_begin_void_4(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042EAF0 */

/* merge_units: begin func_0042EB20 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Keep reference validity and iterator values distinct across callbacks. */
#pragma opt_propagation off

#include "net_transfer_types.h"
#include "alloc_guard.h"

struct TransferUpdateController : TransferController {
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual unsigned char transfer_mode(); /* +0x88 */
    virtual void slot33();
    virtual void slot34();
    virtual bool ready_to_release(); /* +0x94 */
};

struct TransferUpdateObject {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void release_transfer(); /* +0x20 */
};

extern "C" {
extern RbTree D_00582700;
extern char D_004BFB00[];
#if 0 /* merge_units */
void std_tree_pair_int_value_compare_begin_void_3(TransferReferenceIterator* result, RbTree* tree);
#endif /* merge_units */
#define std_tree_pair_int_value_compare_begin_void_3(a0, a1) (std_tree_pair_int_value_compare_begin_void_3((Iter *)(a0), (Tree *)(a1))) /* merge_units */

TransferReferenceIterator std_map_int_tNetActivateTerrainObjectPtr_end(RbTree* tree);
void cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void Tree_Successor(TransferReferenceIterator* position);
void std_tree_pair_int_value_compare_erase_tree_4(RbTree* tree, TransferReferenceIterator* position);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0042CF30(void);
}

static inline cGOBJ* referenced_object(const TransferReference* reference)
{
    cGOBJ* object = reference->object;
    int missing = (object != 0) ^ 1;
    bool valid = true;
    if (!missing && ((GobjEntry*)object)->id.word != reference->id.word)
        valid = false;
    return valid ? object : 0;
}

static inline bool transfer_active(cGOBJ* object)
{
    return object->unk2D != 0 && object->unk2C != 0 && !(object->unk2E != 0);
}

static inline TransferUpdateController* controller(cGOBJ* object)
{
    return (TransferUpdateController*)object->attached;
}

static inline bool release_transfer(cGOBJ* object)
{
    bool released = false;
    if (controller(object)->can_create_message()) {
        ((TransferUpdateObject*)object)->release_transfer();
        released = true;
    }
    return released;
}

static inline void erase_reference(TransferReferenceNode* node)
{
    TransferReferenceIterator erased;
    erased.node = node;
    std_tree_pair_int_value_compare_erase_tree_4(&D_00582700, &erased);
}

static inline void assign_end(TransferReferenceIterator* result, RbTree* tree)
{
    cAssocArray_int_tNetActivateTerrainObjectPtr_Iterator_ctor(result, std_map_int_tNetActivateTerrainObjectPtr_end(tree));
}

static inline void reference_end(TransferReferenceIterator* result)
{
    assign_end(result, &D_00582700);
}

/* Release completed transfers and stale references, then process transfer timers. */
extern "C" void cNetObjectMgr_NextFrame(void)
{
    TransferReferenceIterator position;
    TransferReferenceIterator end;
    TransferReferenceIterator begin;
    cGOBJ* object;
    TransferReferenceNode* node;
    std_tree_pair_int_value_compare_begin_void_3(&begin, &D_00582700);
    position.node = begin.node;
    while (reference_end(&end),
           node = position.node, (node == end.node) ^ 1) {
        object = referenced_object(node->reference);
        Tree_Successor(&position);
        if (object) {
            if (!transfer_active(object) && object->attached &&
                controller(object)->transfer_mode() == 2 &&
                controller(object)->ready_to_release() && release_transfer(object)) {
                TransferReference* reference = node->reference;
                {
                    AllocGuard guard;
                    Mem_Free(0, reference, D_004BFB00, 0x40);
                }
                erase_reference(node);
            }
        } else {
            TransferReference* reference = node->reference;
            {
                AllocGuard guard;
                Mem_Free(0, reference, D_004BFB00, 0x4A);
            }
            erase_reference(node);
        }
    }
    func_0042CF30();
}
#undef std_tree_pair_int_value_compare_begin_void_3 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042EB20 */

/* merge_units: begin func_0042EDF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "transfer_cleanup_types.h"

/* These maps use the registry's common unsigned-ID node header. */
template <class Node> static inline void find_id(Node** result, RbTree* tree,
                                                const GobjId* id)
{
    GobjMapNode* node = (GobjMapNode*)tree->root;
    GobjMapNode* candidate = (GobjMapNode*)&tree->root;
    while (node) {
        if (!(node->key < id->word)) {
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (candidate == (GobjMapNode*)&tree->root || id->word < candidate->key)
        *result = (Node*)&tree->root;
    else
        *result = (Node*)candidate;
}

/* Find an exact object-map ID, returning the map's sentinel when absent. */
extern "C" void ObjMap_Find_42EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact pending-message ID, returning the map's sentinel when absent. */
extern "C" void ObjMap_Find_42EE70(PendingTransferIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact registered-reference ID, returning the map's sentinel when absent. */
extern "C" void ObjMap_Find_42EEF0(TransferReferenceIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact timer ID, returning the map's sentinel when absent. */
extern "C" void ObjMap_Find_42EF70(TransferTimerIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042EDF0 */

/* merge_units: begin func_0042EFF0 */
#pragma push /* merge_units */
#include "NetObjectMgr_types.h"

extern void std_tree_pair_int_value_compare_destroy_nodeP_5(RbTree* tree, void* node);

/* Clears the tree: erases all nodes from the root down, then resets the header. */
void std_tree_pair_int_value_compare_clear_void_2(RbTree* tree) {
    if (tree->root != 0) {
        std_tree_pair_int_value_compare_destroy_nodeP_5(tree, tree->root);
        tree->count = 0;
        tree->root = 0;
        tree->leftmost = &tree->root;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0042EFF0 */
