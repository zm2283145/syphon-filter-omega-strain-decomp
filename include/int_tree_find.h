#ifndef INT_TREE_FIND_H
#define INT_TREE_FIND_H

/*
 * Red-black tree find(key) for an int key (at node +0xC) with the default
 * less-than compare, shared by identical template clones. The iterator is
 * returned through the hidden result pointer; end() is the header at
 * tree +4. C++ only (#pragma cplusplus on before including).
 */
struct IntTreeNode {
    IntTreeNode* left;
    IntTreeNode* right;
    int parentAndColor;
    int key;
};

struct IntTree {
    int count;
    IntTreeNode* root;
};

struct IntTreeIter {
    IntTreeNode* node;
    IntTreeIter(IntTreeNode* n) : node(n) {}
};

#define DEFINE_INT_TREE_FIND(name)                                            \
    extern "C" IntTreeIter name(IntTree* tree, const int* key)                \
    {                                                                         \
        IntTreeNode* x = tree->root;                                          \
        IntTreeNode* y = (IntTreeNode*)&tree->root;                           \
        while (x) {                                                           \
            bool lt = x->key < *key;                                          \
            if (!lt) {                                                        \
                y = x;                                                        \
                x = x->left;                                                  \
            } else                                                            \
                x = x->right;                                                 \
        }                                                                     \
        if (y == (IntTreeNode*)&tree->root || *key < y->key)                  \
            return IntTreeIter((IntTreeNode*)&tree->root);                    \
        return IntTreeIter(y);                                                \
    }

#endif /* INT_TREE_FIND_H */