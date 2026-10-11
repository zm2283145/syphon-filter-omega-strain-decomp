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
extern "C" void func_0042EDF0(TransferObjectIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact pending-message ID, returning the map's sentinel when absent. */
extern "C" void func_0042EE70(PendingTransferIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact registered-reference ID, returning the map's sentinel when absent. */
extern "C" void func_0042EEF0(TransferReferenceIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}

/* Find an exact timer ID, returning the map's sentinel when absent. */
extern "C" void func_0042EF70(TransferTimerIterator* result, RbTree* tree, const GobjId* id)
{
    find_id(&result->node, tree, id);
}
