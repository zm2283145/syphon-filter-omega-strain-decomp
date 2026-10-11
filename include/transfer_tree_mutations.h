#ifndef TRANSFER_TREE_MUTATIONS_H
#define TRANSFER_TREE_MUTATIONS_H

#include "transfer_tree_destroy.h"
#include "transfer_cleanup_types.h"

struct TransferObjectValue { GobjId id; TransferObjectEntry* entry; };
struct TransferObjectInsertResult { TransferObjectIterator position; unsigned char inserted; };
struct PendingTransferValue { GobjId id; TransferMessage* message; };
struct PendingTransferInsertResult { PendingTransferIterator position; unsigned char inserted; };

extern "C" void func_0013C800(TransferTreeNode* node, void* root);

template <class Node>
static inline void transfer_tree_next(Node** position)
{
    TransferTreeNode* node = ((TransferTreeNode*)*position)->right;
    TransferTreeNode* parent;
    if (node) {
        TransferTreeNode* left = node->left;
        while (left) {
            node = left;
            left = left->left;
        }
        *position = (Node*)node;
        return;
    }
    /* The parent pointer's low bit stores the red-black color. */
    while ((TransferTreeNode*)*position !=
           (parent = (TransferTreeNode*)((unsigned int)((TransferTreeNode*)*position)->parent & ~1U))->left)
        *position = (Node*)parent;
    *position = (Node*)parent;
}

template <class Node>
static inline void transfer_tree_advance_minimum(Node** position, void** minimum)
{
    transfer_tree_next(position);
    *minimum = *position;
}

static inline void** transfer_tree_minimum(RbTree* tree)
{
    return &tree->leftmost;
}

/* Keep the minimum's address live while advancing an iterator in place. */
template <char* File, class Node>
static inline void transfer_tree_erase(RbTree* tree, Node** position)
{
    void** minimum = transfer_tree_minimum(tree);
    void* leftmost = tree->leftmost;
    Node* node = *position;
    if (node == leftmost)
        transfer_tree_advance_minimum(position, minimum);
    func_0013C800((TransferTreeNode*)node, tree->root);
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, File, 0x64);
    }
    tree->count--;
}

template <
    class Node, class Value, class Result,
    Node* (*Create)(RbTree*, TransferTreeNode*, bool, bool, const Value*),
    unsigned char* Inserted, unsigned char* Duplicate
> struct TransferTreeInsert {
    static inline void insert(Result* result, RbTree* tree, const Value* value)
    {
        bool left = true;
        TransferTreeNode* previous = 0;
        TransferTreeNode* parent = (TransferTreeNode*)&tree->root;
        TransferTreeNode* node = (TransferTreeNode*)tree->root;
        bool leftmost = true;
        while (node) {
            parent = node;
            if (value->id.word < node->id.word) {
                node = node->left;
                left = true;
            } else {
                previous = node;
                node = node->right;
                left = false;
                leftmost = false;
            }
        }
        if (!previous || previous->id.word < value->id.word) {
            result->position.node = Create(tree, parent, left, leftmost, value);
            result->inserted = *Inserted;
        } else {
            result->position.node = (Node*)previous;
            result->inserted = *Duplicate;
        }
    }
};

#endif
